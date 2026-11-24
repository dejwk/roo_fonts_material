# roo_fonts_material 1.1.3

- Fix Arduino dependency discovery by adding top-level `roo_display.h` includes to the font library and `roo_backport.h` to the font example.
- Upgrade `roo_display` to 3.5.0 in Bazel and raise the PlatformIO minimum to 3.5.0.
- Upgrade Bazel’s `roo_testing` dependency to 2.7.1 and update CI to `roo_testing` 2.7.0 with the `arduino_esp32` profile.
- Update the Bazel launcher and add host-test profile files for ESP32, ESP32-S3, ESP32-C3, and RP2040, along with a nine-profile test runner.

---

# roo_fonts_material 1.1.2

- Upgrade `roo_display` to 3.3.0 in Bazel and raise the PlatformIO minimum requirement to 3.3.0.
- Upgrade Bazel’s `rules_cc` to 0.2.25 and `roo_testing` to 2.1.2; update CI to use `roo_testing` 2.1.2.
- Add consolidated release notes for previous releases.

---

# [roo_fonts_material 1.1.1](https://github.com/dejwk/roo_fonts_material/releases/tag/1.1.1)

Published 2026-08-30.

This maintenance release improves the host-development experience and project automation.

### Highlights

- Added a runnable emulator example for the Material font catalog:

  ```sh
  bazel run //examples/fonts:fonts
  ```

- Adopted `roo_testing` 2.0 ESP32 host profiles, including AddressSanitizer support.
- Updated Bazel, CI automation, and project dependencies.

No font catalog or public API changes were introduced in this release.

**Full Changelog:** https://github.com/dejwk/roo_fonts_material/compare/1.1.0...1.1.1

---

# [roo_fonts_material 1.1.0](https://github.com/dejwk/roo_fonts_material/releases/tag/1.1.0)

Published 2026-08-07.

* Added many new fonts to support Material3 typography at 4 scales.
* Added subscripts for small integers (2-5).

**Full Changelog**: https://github.com/dejwk/roo_fonts_material/compare/1.0.0...1.1.0

---

# [roo_fonts_material 1.0.0](https://github.com/dejwk/roo_fonts_material/releases/tag/1.0.0)

Published 2026-02-27.

Initial release.

---

