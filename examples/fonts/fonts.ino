// NOTE: this test uses multiple font files of different sizes and produces a
// large binary. To deploy it to stock ESP32, you might need to use a
// non-standard partition table, e.g. huge_app.csv:
// https://github.com/espressif/arduino-esp32/blob/master/tools/partitions/huge_app.csv

// See
// https://docs.platformio.org/en/latest/platforms/espressif32.html#partition-tables
// for details.

#include "Arduino.h"

#ifdef ROO_TESTING

#include "roo_testing/devices/display/st77xx/st77xx.h"
#include "roo_testing/microcontrollers/esp32/fake_esp32.h"
#include "roo_testing/transducers/ui/viewport/flex_viewport.h"
#include "roo_testing/transducers/ui/viewport/fltk/fltk_viewport.h"

using roo_testing_transducers::FlexViewport;
using roo_testing_transducers::FltkViewport;

struct Emulator {
  FltkViewport viewport;
  FlexViewport flexViewport;

  FakeSt77xxSpi display;

  Emulator()
      : viewport(), flexViewport(viewport, 2), display(flexViewport, 240, 240) {
    FakeEsp32().attachSpiDevice(display, 18, 19, 23);
    FakeEsp32().gpio.attachOutput(5, display.cs());
    FakeEsp32().gpio.attachOutput(2, display.dc());
    FakeEsp32().gpio.attachOutput(4, display.rst());
  }
} emulator;

#endif

#include "roo_backport/string_view.h"
#include "roo_display.h"
#include "roo_display/ui/text_label.h"
#include "roo_fonts/NotoSans_Condensed/11.h"
#include "roo_fonts/NotoSans_Condensed/14.h"
#include "roo_fonts/NotoSans_Condensed/16.h"
#include "roo_fonts/NotoSans_Condensed/20.h"
#include "roo_fonts/NotoSans_Condensed/24.h"
#include "roo_fonts/NotoSans_Condensed/28.h"
#include "roo_fonts/NotoSans_Condensed/36.h"
#include "roo_fonts/NotoSans_Condensed/51.h"
#include "roo_fonts/NotoSans_Condensed/72.h"
#include "roo_fonts/NotoSans_Condensed/9.h"
#include "roo_fonts/NotoSans_CondensedLight/45.h"
#include "roo_fonts/NotoSans_CondensedLight/60.h"
#include "roo_fonts/NotoSans_CondensedLight/72.h"
#include "roo_fonts/NotoSans_CondensedLight/90.h"
#include "roo_fonts/NotoSans_CondensedMedium/11.h"
#include "roo_fonts/NotoSans_CondensedMedium/20.h"
#include "roo_fonts/NotoSans_CondensedMedium/28.h"
#include "roo_fonts/NotoSans_CondensedMedium/40.h"
#include "roo_fonts/NotoSans_Light/45.h"
#include "roo_fonts/NotoSans_Light/60.h"
#include "roo_fonts/NotoSans_Light/72.h"
#include "roo_fonts/NotoSans_Light/90.h"
#include "roo_fonts/NotoSans_Medium/11.h"
#include "roo_fonts/NotoSans_Medium/20.h"
#include "roo_fonts/NotoSans_Medium/28.h"
#include "roo_fonts/NotoSans_Medium/40.h"
#include "roo_fonts/NotoSans_Regular/11.h"
#include "roo_fonts/NotoSans_Regular/14.h"
#include "roo_fonts/NotoSans_Regular/16.h"
#include "roo_fonts/NotoSans_Regular/20.h"
#include "roo_fonts/NotoSans_Regular/24.h"
#include "roo_fonts/NotoSans_Regular/28.h"
#include "roo_fonts/NotoSans_Regular/36.h"
#include "roo_fonts/NotoSans_Regular/51.h"
#include "roo_fonts/NotoSans_Regular/72.h"
#include "roo_fonts/NotoSans_Regular/9.h"

using namespace roo_display;

#include "roo_display/driver/st7789.h"
St7789spi_240x240<5, 2, 4> device;
Display display(device);

struct FontSample {
  const char* size_label;
  const Font& font;
};

const FontSample kRegularSamples[] = {
    {"9", font_NotoSans_Regular_9()},   {"11", font_NotoSans_Regular_11()},
    {"14", font_NotoSans_Regular_14()}, {"16", font_NotoSans_Regular_16()},
    {"20", font_NotoSans_Regular_20()}, {"24", font_NotoSans_Regular_24()},
    {"28", font_NotoSans_Regular_28()}, {"36", font_NotoSans_Regular_36()},
    {"51", font_NotoSans_Regular_51()}, {"72", font_NotoSans_Regular_72()},
};

const FontSample kLightSamples[] = {
    {"45", font_NotoSans_Light_45()},
    {"60", font_NotoSans_Light_60()},
    {"72", font_NotoSans_Light_72()},
    {"90", font_NotoSans_Light_90()},
};

const FontSample kMediumSamples[] = {
    {"11", font_NotoSans_Medium_11()},
    {"20", font_NotoSans_Medium_20()},
    {"28", font_NotoSans_Medium_28()},
    {"40", font_NotoSans_Medium_40()},
};

const FontSample kCondensedSamples[] = {
    {"9", font_NotoSans_Condensed_9()},   {"11", font_NotoSans_Condensed_11()},
    {"14", font_NotoSans_Condensed_14()}, {"16", font_NotoSans_Condensed_16()},
    {"20", font_NotoSans_Condensed_20()}, {"24", font_NotoSans_Condensed_24()},
    {"28", font_NotoSans_Condensed_28()}, {"36", font_NotoSans_Condensed_36()},
    {"51", font_NotoSans_Condensed_51()}, {"72", font_NotoSans_Condensed_72()},
};

const FontSample kCondensedLightSamples[] = {
    {"45", font_NotoSans_CondensedLight_45()},
    {"60", font_NotoSans_CondensedLight_60()},
    {"72", font_NotoSans_CondensedLight_72()},
    {"90", font_NotoSans_CondensedLight_90()},
};

const FontSample kCondensedMediumSamples[] = {
    {"11", font_NotoSans_CondensedMedium_11()},
    {"20", font_NotoSans_CondensedMedium_20()},
    {"28", font_NotoSans_CondensedMedium_28()},
    {"40", font_NotoSans_CondensedMedium_40()},
};

int16_t printLn(DrawingContext& dc, const Font& font, int16_t x, int16_t y,
                roo::string_view text, Color color) {
  dc.draw(StringViewLabel(text, font, color, FillMode::kExtents), x,
          y + font.metrics().glyphYMax());
  return font.metrics().linespace() + 1;
}

void setup() {
  Serial.begin(115200);
  SPI.begin();
  display.init(color::Gainsboro);
}

int16_t printText(const char* family_name, const FontSample* samples,
                  size_t sample_count) {
  DrawingContext dc(display);
  dc.fill(color::Gainsboro);
  const char* text = "Zażółć gęślą jaźń 12345.67890 !@#$%^&*()";
  Color color = color::Black;

  const Color backgrounds[] = {
      color::Beige,      color::PapayaWhip, color::PowderBlue,
      color::LightGreen, color::MistyRose,  color::LemonChiffon,
  };
  const size_t background_count = sizeof(backgrounds) / sizeof(backgrounds[0]);

  int16_t y = 1;
  dc.setBackgroundColor(color::Gainsboro);
  y += printLn(dc, kRegularSamples[0].font, 4, y, family_name, color::Black);

  for (size_t i = 0; i < sample_count; ++i) {
    const FontSample& sample = samples[i];
    const Color bg = backgrounds[i % background_count];
    String line = String("Size ") + sample.size_label + ": " + text;
    dc.setBackgroundColor(bg);
    y += printLn(dc, sample.font, 6, y, line.c_str(), color);
  }
  delay(1000);
  return y;
}

void loop() {
  printText("NotoSans Regular", kRegularSamples,
            sizeof(kRegularSamples) / sizeof(kRegularSamples[0]));
  printText("NotoSans Light", kLightSamples,
            sizeof(kLightSamples) / sizeof(kLightSamples[0]));
  printText("NotoSans Medium", kMediumSamples,
            sizeof(kMediumSamples) / sizeof(kMediumSamples[0]));
  printText("NotoSans Condensed", kCondensedSamples,
            sizeof(kCondensedSamples) / sizeof(kCondensedSamples[0]));
  printText("NotoSans Condensed Light", kCondensedLightSamples,
            sizeof(kCondensedLightSamples) / sizeof(kCondensedLightSamples[0]));
  printText(
      "NotoSans Condensed Medium", kCondensedMediumSamples,
      sizeof(kCondensedMediumSamples) / sizeof(kCondensedMediumSamples[0]));

  delay(1200);
}
