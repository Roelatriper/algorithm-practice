#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 || $# -gt 2 ]]; then
  echo "用法: ./scripts/debug.sh <source.cpp> [input.txt]" >&2
  exit 2
fi

source_file="$1"
if [[ ! -f "$source_file" ]]; then
  echo "找不到源文件: $source_file" >&2
  exit 2
fi
if [[ $# -eq 2 && ! -f "$2" ]]; then
  echo "找不到输入文件: $2" >&2
  exit 2
fi

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
build_dir="$repo_root/.build/debug"
compiler="${CXX:-c++}"
base_name="$(basename "${source_file%.cpp}")"
binary="$build_dir/$base_name"
mkdir -p "$build_dir"

"$compiler" \
  -std=c++03 -Wall -Wextra -Wpedantic -pedantic-errors \
  -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer \
  "$source_file" -o "$binary"

echo "已开启内存与未定义行为检查。" >&2
if [[ $# -eq 2 ]]; then
  exec "$binary" < "$2"
else
  echo "请输入题目数据：" >&2
  exec "$binary"
fi
