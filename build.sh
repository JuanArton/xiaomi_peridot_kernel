#!/usr/bin/env bash
# shellcheck disable=SC2199
# shellcheck source=/dev/null

#
# Copyright (C) 2020-22 UtsavBalar1231
# SPDX-License-Identifier: Apache-2.0
#

#set -euo pipefail

# ─── CONFIGURATION ──────────────────────────────────────────────────────────────

export PATH="$HOME/tc/clang/bin:$PATH"
export LD_LIBRARY_PATH="$HOME/tc/clang/lib64:$LD_LIBRARY_PATH"

KBUILD_COMPILER_STRING="$("$HOME/tc/clang/bin/clang" --version | head -n 1 | sed -E 's/\(http.*?\)//g' | sed -E 's/\s+/ /g' | sed 's/[[:space:]]*$//')"
KBUILD_LINKER_STRING="$("$HOME/tc/clang/bin/ld.lld" --version | head -n 1 | sed -E 's/\(http.*?\)//g' | sed -E 's/\s+/ /g' | sed -E 's/\(compatible with [^)]*\)//' | sed 's/[[:space:]]*$//')"
export KBUILD_COMPILER_STRING
export KBUILD_LINKER_STRING

DATE=$(date '+%Y%m%d-%H%M')
VERSION="Antergos-PERIDOT-${DATE}"
OUT_DIR="out"
DEFCONFIG="peridot_defconfig"
LOG_FILE="${OUT_DIR}/build.log"

JOBS=$(nproc)
echo "Jobs: $JOBS"

ARGS=(
    ARCH=arm64
    O="$OUT_DIR"
    CC="ccache clang"
    LD=ld.lld
    CLANG_TRIPLE=aarch64-linux-gnu-
    CROSS_COMPILE=aarch64-linux-gnu-
    CROSS_COMPILE_COMPAT=arm-linux-gnueabi-
    -j"$JOBS"
)

# ─── COMPILATION ────────────────────────────────────────────────────────────────

echo "------ Starting Compilation ------"
START=$(date +%s)

make "${ARGS[@]}" "$DEFCONFIG"

make -C "$OUT_DIR" "${ARGS[@]}" HOSTCC="ccache gcc" HOSTCXX="ccache g++" olddefconfig

make "${ARGS[@]}" HOSTCC="ccache gcc" HOSTCXX="ccache g++" 2>&1 | tee "$LOG_FILE"

END=$(date +%s)
ELAPSED=$((END - START))

echo "------ Compilation Finished in ${ELAPSED}s ------"
