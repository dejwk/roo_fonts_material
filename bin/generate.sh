#!/bin/bash

abs_path () {
  echo "$(cd -- "$(dirname -- "$1")"; pwd)/$(basename -- "$1")"
}

BIN_DIR="$(abs_path "`dirname $0`")"
OUT_DIR="$(abs_path "$BIN_DIR/../src/roo_fonts")"

SIZES_REGULAR='9,11,14,16,20,21,24,26,28,32,34,36,48,51,68,72,96'
SIZES_LIGHT='45,60,72,90,96,120,144,192'
SIZES_MEDIUM='11,14,15,20,21,28,30,40'

FONTS_REGULAR=(
  "NotoSans-Regular"
  "NotoSans-Condensed"
)

FONTS_LIGHT=(
  "NotoSans-Light"
  "NotoSans-CondensedLight"
)

FONTS_MEDIUM=(
  "NotoSans-Medium"
  "NotoSans-CondensedMedium"
)

mkdir -p ${OUT_DIR}

(cd ${BIN_DIR};
git clone https://github.com/dejwk/roo_display_font_importer.git;
cd roo_display_font_importer;
git checkout v2;

for font in "${FONTS_REGULAR[@]}"; do
  ./gradlew run --args="-font=$font -sizes=$SIZES_REGULAR -output-dir=$OUT_DIR"
done

for font in "${FONTS_LIGHT[@]}"; do
  ./gradlew run --args="-font=$font -sizes=$SIZES_LIGHT -output-dir=$OUT_DIR"
done

for font in "${FONTS_MEDIUM[@]}"; do
  ./gradlew run --args="-font=$font -sizes=$SIZES_MEDIUM -output-dir=$OUT_DIR"
done
)
