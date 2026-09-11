#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
  echo "用法: ./scripts/build.sh <source.cpp>" >&2
  exit 2
fi

source_file="$1"
if [[ ! -f "$source_file" ]]; then
  echo "找不到源文件: $source_file" >&2
  exit 2
fi

repo_root="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
build_dir="$repo_root/.build"
compiler="${CXX:-c++}"
base_name="$(basename "${source_file%.cpp}")"
output_file="$build_dir/$base_name"

mkdir -p "$build_dir"

echo "编译器: $compiler" >&2
"$compiler" \
  -std=c++17 \
  -Wall \
  -Wextra \
  -Wpedantic \
  -O2 \
  "$source_file" \
  -o "$output_file"

echo "$output_file"
