# das_kb4_bara2/r2023_12

![das_kb4_bara2/r2023_12](imgur.com image replace me!)

This is a replacement controller board for the Das Keyboard Pro 4.
Definitely see also https://github.com/qmk/qmk_firmware/blob/master/keyboards/handwired/daskeyboard/daskeyboard4/
which made this project vastly shorter!

* Keyboard Maintainer: [Karl Palsson](https://github.com/karlp)
* Hardware Supported: Presently working with the r2023-12 hardware revision.
* Hardware Availability: https://www.daskeyboard.com/de/daskeyboard-4-professional/

## Status
Perfectly functional replacement, all keys work.  The rotary encoder works. The LEDs all work.
The PCB design is not 100% correct, so the housings and inserts don't mate correctly together.

The PCB design files are available from https://github.com/karlp/das-kb4-bara2/

Make example for this keyboard (after setting up your build environment):

    make das_kb4_bara2/r2023_12:default

Flashing example for this keyboard:

    make das_kb4_bara2/r2023_12:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: TBD? Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Hold down the "mute" button when plugging it in.
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
