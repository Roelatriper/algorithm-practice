#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 || $# -gt 2 ]]; then
  echo "用法: ./scripts/run.sh <source.cpp> [input.txt]" >&2
  exit 2
fi

repo_root="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
binary="$("$repo_root/scripts/build.sh" "$1")"

if [[ $# -eq 2 ]]; then
  if [[ ! -f "$2" ]]; then
    echo "找不到输入文件: $2" >&2
    exit 2
  fi
  "$binary" < "$2"
else
  "$binary"
fi
