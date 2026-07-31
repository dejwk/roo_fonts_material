#!/bin/bash

abs_path () {
  echo "$(cd -- "$(dirname -- "$1")"; pwd)/$(basename -- "$1")"
}

BIN_DIR="$(abs_path "`dirname $0`")"
OUT_DIR="$(abs_path "$BIN_DIR/../src/roo_fonts")"

SIZES_REGULAR='9,10.5,11,14,16,16.5,20,21,22,24,26,28,32,33,34,36,42,44,48,51,54,56,64,68,72,86,96,114'
SIZES_LIGHT='45,60,72,90,96,120,144,192'
SIZES_MEDIUM='8.25,9,10.5,11,12,14,15,16,16.5,18,20,21,22,24,28,30,32,40'

# These condensed faces intentionally retain their original size sets: Material 3
# typography uses the non-condensed Regular and Medium faces only.
SIZES_CONDENSED='9,11,14,16,20,21,24,26,28,32,34,36,48,51,68,72,96'
SIZES_CONDENSED_MEDIUM='11,14,15,20,21,28,30,40'

FONTS_LIGHT=(
  "NotoSans-Light"
  "NotoSans-CondensedLight"
)

mkdir -p ${OUT_DIR}

(cd ${BIN_DIR};
git clone https://github.com/dejwk/roo_display_font_importer.git;
cd roo_display_font_importer;

./gradlew run --args="-font=NotoSans-Regular -sizes=$SIZES_REGULAR -output-dir=$OUT_DIR"
./gradlew run --args="-font=NotoSans-Condensed -sizes=$SIZES_CONDENSED -output-dir=$OUT_DIR"

for font in "${FONTS_LIGHT[@]}"; do
  ./gradlew run --args="-font=$font -sizes=$SIZES_LIGHT -output-dir=$OUT_DIR"
done

./gradlew run --args="-font=NotoSans-Medium -sizes=$SIZES_MEDIUM -output-dir=$OUT_DIR"
./gradlew run --args="-font=NotoSans-CondensedMedium -sizes=$SIZES_CONDENSED_MEDIUM -output-dir=$OUT_DIR"
)
