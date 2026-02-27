load("@rules_cc//cc:cc_library.bzl", "cc_library")
load("@rules_cc//cc:cc_test.bzl", "cc_test")

cc_library(
    name = "roo_fonts_material",
    srcs = glob(
        [
            "src/**/*.cpp",
            "src/**/*.h",
        ],
        exclude = ["test/**"],
    ),
    includes = [
        "src",
    ],
    linkstatic = 1,
    visibility = ["//visibility:public"],
    deps = [
        "@roo_display",
    ],
)

cc_test(
    name = "font_test",
    srcs = [
        "test/font_test.cpp",
    ],
    linkstatic = 1,
    deps = [
        ":roo_fonts_material",
        "@roo_display//:testing",
    ],
)
