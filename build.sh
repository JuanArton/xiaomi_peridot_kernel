#!/usr/bin/env bash
# shellcheck disable=SC2199
# shellcheck source=/dev/null

#
# Copyright (C) 2020-22 UtsavBalar1231
# SPDX-License-Identifier: Apache-2.0
#

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

# ─── POST BUILD ACTIONS ─────────────────────────────────────────────────────────

# Expecting parameters, example: ./build.sh 5 zn
FIRST_PARAM=$1
FLAG=$2

BOOT_IMG="${OUT_DIR}/arch/arm64/boot/Image.gz"
TEMPLATE_DIR="/home/juan/Kernel/out/template"
DEST_FILE="$TEMPLATE_DIR/Image.gz"

if [[ ! -f "$BOOT_IMG" ]]; then
    echo "Image.gz not found at $BOOT_IMG"
    exit 1
fi

echo "Copying Image.gz to template folder"
mkdir -p "$TEMPLATE_DIR"
cp "$BOOT_IMG" "$DEST_FILE"

ZIP_NAME=""
DEST_PATH=""

case "$FLAG" in
    zn)
        ZIP_NAME="Antergos-Z-V${FIRST_PARAM}-NonKSU.zip"
        DEST_PATH="/home/juan/Kernel/out/battery"
        ;;
    zksu)
        ZIP_NAME="Antergos-Z-V${FIRST_PARAM}-KSU.zip"
        DEST_PATH="/home/juan/Kernel/out/battery"
        ;;
    xn)
        ZIP_NAME="Antergos-X-V${FIRST_PARAM}-NonKSU.zip"
        DEST_PATH="/home/juan/Kernel/out/perf"
        ;;
    xksu)
        ZIP_NAME="Antergos-X-V${FIRST_PARAM}-KSU.zip"
        DEST_PATH="/home/juan/Kernel/out/perf"
        ;;
    *)
        echo "Invalid flag provided: $FLAG"
        echo "Use: zn, zksu, xn, xksu"
        exit 1
        ;;
esac

mkdir -p "$DEST_PATH"
cd "$TEMPLATE_DIR" || exit 1
zip -r "$DEST_PATH/$ZIP_NAME" ./*
cd - || exit

echo "Zip created at $DEST_PATH/$ZIP_NAME"
