#include "gtest/gtest.h"
#include "roo_display.h"
#include "roo_display/font/font.h"
#include "roo_fonts/NotoSans_Regular/14.h"
#include "testing_drawable.h"

namespace roo_display {

const Font& font() { return font_NotoSans_Regular_14(); }

class Label : public Drawable {
 public:
  explicit Label(const string& label) : label_(label) {}

 private:
  void drawTo(const Surface& s) const override {
    font().drawHorizontalString(s, label_, color::White);
  }

  Box extents() const override {
    return font().getHorizontalStringMetrics(label_).screen_extents();
  }

  std::string label_;
};

TEST(FontTest, NotoSansRegular14Metrics) {
  EXPECT_EQ(19, font().metrics().linespace());
  EXPECT_EQ(11, font().metrics().ascent());
  EXPECT_EQ(-4, font().metrics().descent());
  EXPECT_EQ(4, font().metrics().linegap());
  EXPECT_EQ(-3, font().metrics().glyphXMin());
  EXPECT_EQ(-3, font().metrics().glyphYMin());
  EXPECT_EQ(15, font().metrics().glyphXMax());
  EXPECT_EQ(15, font().metrics().glyphYMax());
  EXPECT_EQ(19, font().metrics().maxWidth());
  EXPECT_EQ(19, font().metrics().maxHeight());
}

TEST(FontTest, NotoSansRegular14GoldenText) {
  FakeScreen<Argb4444> screen(30, 18, color::Black);
  screen.Draw(Label("Aftp"), 0, 12);

  EXPECT_THAT(screen, MatchesContent(Grayscale4(), 30, 18,
                                     "                              "
                                     "           8EE3               "
                                     "   4*3    4E32 58             "
                                     "   AD9    7C   98             "
                                     "  1*5E   8***99***A C4AED5    "
                                     "  7C D6   7C1  B81  CE516*4   "
                                     "  D6 7C   7B   B8   C9   AA   "
                                     " 3*1 2*2  7B   B8   C7   7C   "
                                     " 9*****8  7B   B8   C7   8C   "
                                     " E62227E  7B   B8   C9   A9   "
                                     "6D     E5 7B   9C11 CE515*3   "
                                     "C7     9B 7B   1C*A C7B*D6    "
                                     "                    C6        "
                                     "                    C6        "
                                     "                    C6        "
                                     "                    C6        "
                                     "                              "
                                     "                              "));
}

}  // namespace roo_display
