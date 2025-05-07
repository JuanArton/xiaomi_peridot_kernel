#!/usr/bin/env bash
# shellcheck disable=SC2199
# shellcheck source=/dev/null

#
# Copyright (C) 2020-22 UtsavBalar1231
# SPDX-License-Identifier: Apache-2.0
#

# ─── USER INPUT ────────────────────────────────────────────────────────────────

read -rp "Enter kernel version (e.g. 5): " FIRST_PARAM

echo "Select build variant:"
echo "1) zn   (Z - NonKSU)"
echo "2) zksu (Z - KSU)"
echo "3) zksus (S - KSU)"
echo "4) xn   (X - NonKSU)"
echo "5) xksu (X - KSU)"
echo "6) xksus (X - KSUS)"
read -rp "Enter choice [1-4]: " variant_choice

case "$variant_choice" in
    1) FLAG="zn" ;;
    2) FLAG="zksu" ;;
    3) FLAG="zksus" ;;
    4) FLAG="xn" ;;
    5) FLAG="xksu" ;;
    6) FLAG="xksus" ;;
    *) echo "Invalid choice. Exiting." && exit 1 ;;
esac

# ─── CONFIGURATION ──────────────────────────────────────────────────────────────

export PATH="$HOME/tc/clang/bin:$PATH"
export LD_LIBRARY_PATH="$HOME/tc/clang/lib64:$LD_LIBRARY_PATH"

KBUILD_COMPILER_STRING="$("$HOME/tc/clang/bin/clang" --version | head -n 1 | sed -E 's/\(http.*?\)//g' | sed -E 's/\s+/ /g' | sed 's/[[:space:]]*$//')"
KBUILD_LINKER_STRING="$("$HOME/tc/clang/bin/ld.lld" --version | head -n 1 | sed -E 's/\(http.*?\)//g' | sed -E 's/\s+/ /g' | sed -E 's/\(compatible with [^)]*\)//' | sed 's/[[:space:]]*$//')"
export KBUILD_COMPILER_STRING
export KBUILD_LINKER_STRING
export KBUILD_BUILD_USER="antergos"
export KBUILD_BUILD_HOST="peridot"

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

BOOT_IMG="${OUT_DIR}/arch/arm64/boot/Image.gz"
TEMPLATE_DIR="$HOME/Kernel/out/template"
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
        DEST_PATH="$HOME/Kernel/out/battery"
        ;;
    zksu)
        ZIP_NAME="Antergos-Z-V${FIRST_PARAM}-KSU.zip"
        DEST_PATH="$HOME/Kernel/out/battery"
        ;;
    zksus)
        ZIP_NAME="Antergos-Z-V${FIRST_PARAM}-KSUS.zip"
        DEST_PATH="$HOME/Kernel/out/battery"
        ;;
    xn)
        ZIP_NAME="Antergos-X-V${FIRST_PARAM}-NonKSU.zip"
        DEST_PATH="$HOME/Kernel/out/perf"
        ;;
    xksu)
        ZIP_NAME="Antergos-X-V${FIRST_PARAM}-KSU.zip"
        DEST_PATH="$HOME/Kernel/out/perf"
        ;;
    xksus)
        ZIP_NAME="Antergos-X-V${FIRST_PARAM}-KSUS.zip"
        DEST_PATH="$HOME/Kernel/out/perf"
        ;;
esac

mkdir -p "$DEST_PATH"
cd "$TEMPLATE_DIR" || exit 1
zip -r "$DEST_PATH/$ZIP_NAME" ./*
cd - || exit

echo "Zip created at $DEST_PATH/$ZIP_NAME"
