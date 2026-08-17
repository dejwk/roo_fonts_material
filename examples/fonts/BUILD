load("@roo_testing//roo_testing/emulation:arduino.bzl", "roo_arduino_example")

roo_arduino_example(
    name = "fonts",
    sketch = "fonts.ino",
    visibility = ["//visibility:public"],
    deps = [
        "//:roo_fonts_material",
        "@roo_display",
        "@roo_testing//roo_testing/devices/display/st77xx:spi",
        "@roo_testing//roo_testing/microcontrollers/esp32",
        "@roo_testing//roo_testing/transducers/ui/viewport:flex",
        "@roo_testing//roo_testing/transducers/ui/viewport/fltk",
    ],
)
