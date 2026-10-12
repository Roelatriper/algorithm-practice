#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 1 ]]; then
  echo "用法: ./scripts/build-debug.sh <source.cpp>" >&2
  exit 2
fi

source_file="$1"
if [[ ! -f "$source_file" ]]; then
  echo "找不到源文件: $source_file" >&2
  exit 2
fi

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
build_dir="$repo_root/.build/gui-debug"
compiler="${CXX:-c++}"
base_name="$(basename "${source_file%.cpp}")"
output_file="$build_dir/$base_name"
mkdir -p "$build_dir"

echo "编译器: ${compiler}（断点调试）" >&2
"$compiler" \
  -std=c++03 -Wall -Wextra -Wpedantic -pedantic-errors \
  -g -O0 -fno-omit-frame-pointer \
  "$source_file" -o "$output_file"

echo "$output_file"
