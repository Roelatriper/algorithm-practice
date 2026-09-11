// 生成 stats/data.json：扫描仓库下所有 .cpp 文件，收集文件名/大小/源码
// 用法：node stats/fetch_data.mjs  （在仓库根目录运行）
import fs from "node:fs";
import path from "node:path";
import { execFileSync } from "node:child_process";

const ROOT = path.resolve(process.cwd());
const IGNORE = new Set([".git", "node_modules", "stats"]);

function collectCpp(dir, base = "") {
  const out = [];
  for (const entry of fs.readdirSync(dir, { withFileTypes: true })) {
    if (entry.isDirectory()) {
      if (IGNORE.has(entry.name)) continue;
      out.push(...collectCpp(path.join(dir, entry.name), path.join(base, entry.name)));
    } else if (entry.name.toLowerCase().endsWith(".cpp")) {
      const full = path.join(dir, entry.name);
      const rel = base ? path.join(base, entry.name) : entry.name;
      const code = fs.readFileSync(full, "utf-8");
      out.push({
        name: entry.name,
        path: rel.replace(/\\/g, "/"),
        size: fs.statSync(full).size,
        code,
      });
    }
  }
  return out;
}

const cppFiles = collectCpp(ROOT);

// 使用系统 PATH 中的 Git；如有需要可通过 GIT_PATH 覆盖。
const GIT = process.env.GIT_PATH || "git";
let totalPush = 0;
try {
  totalPush = parseInt(
    execFileSync(GIT, ["rev-list", "--count", "HEAD"], {
      cwd: ROOT,
      encoding: "utf-8",
    }).trim(),
    10
  );
} catch {}

const data = {
  generatedAt: new Date().toISOString(),
  totalFiles: cppFiles.length,
  totalPush,
  files: cppFiles.sort((a, b) => a.name.localeCompare(b.name, "zh-Hans-CN")),
};

const outDir = path.join(ROOT, "stats");
if (!fs.existsSync(outDir)) fs.mkdirSync(outDir, { recursive: true });
fs.writeFileSync(path.join(outDir, "data.json"), JSON.stringify(data, null, 2), "utf-8");
console.log(`✅ 生成 stats/data.json：${cppFiles.length} 个 .cpp 文件`);
