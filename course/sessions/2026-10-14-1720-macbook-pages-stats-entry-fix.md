# 课程记录：GitHub Pages 改为发布统计页面

- 日期时间：2026-10-14 17:20
- 设备：MacBook
- 当前阶段：阶段 3 基础模型入口；仓库维护
- 本次目标：让 GitHub Pages 的站点根路径显示 `stats/index.html`，而不是仓库 `README.md`。

## 学生作答与证据

- 独立用时：不适用；本次为部署配置修复。
- 最高提示等级：不适用；未进行算法作答提示。
- 完成情况：新增 `.github/workflows/deploy-pages.yml`，将 `stats/` 作为 Pages artifact 根目录；监听 `master` 中统计页变化、手动触发以及 `Update Stats` 工作流成功完成。
- 验证：修复前检查稳定复现“存在 `stats/index.html`，但没有选择 `stats/` 的 Pages workflow”；修复后 workflow YAML 可解析，artifact 路径为 `stats`，`data.json` 可解析，本地 HTTP 根路径返回统计页标题且相对 `data.json` 可访问，`git diff --check` 通过。
- 相关文件：`.github/workflows/deploy-pages.yml`、`README.md`、`stats/index.html`、`stats/data.json`；统计页源码未修改。

## 诊断

- 已经做对：`stats/index.html` 与 `data.json` 已构成可直接发布的静态站点，相对路径正确。
- 第一处关键问题：仓库此前只有刷新数据的 workflow，没有 Pages 部署 workflow。Pages 从仓库根目录发布时，根目录没有 `index.html`，会把 `README.md` 作为入口候选。
- 错误类别：GitHub Pages 发布源 / 部署配置。
- 最小反例：根目录有 `README.md`、没有 `index.html`，而真正入口位于 `stats/index.html`；未选择 `stats/` 时站点根路径不可能直接落到统计页。

## 掌握变化

- 新掌握：无；本次不产生算法掌握证据。
- 仍在学习：前缀和延迟重写与迁移、后续二分查找，原计划不变。
- 需要延迟复习：不适用。

## 下一步

1. 提交并推送 workflow；若仓库 Pages 设置仍为 `Deploy from a branch`，在 GitHub `Settings → Pages → Build and deployment → Source` 中一次性改为 `GitHub Actions`。
2. 等待 `Deploy Stats to GitHub Pages` 成功后访问站点根路径；后续 `Update Stats` 完成后会自动重新部署最新 `stats/`。

