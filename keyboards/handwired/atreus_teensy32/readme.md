# Handwired Atreus with a Teensy 3.2

This folder contains the code for my handwired Atreus.
The code is based on the chibios_test/teensy_lc_onekey keyboard and should be mostly compatible with the keymaps from the Atreus Keyboard.
The matrix is wired as described in the following image from the FalbaTech FAQ with the exception that I used a Teensy 3.2 instead of a Teensy 2.0.

![matrix](https://falba.tech/wp-content/uploads/2017/10/manual_atreus.jpg)

I connected the rows and columns to the Teensy as follows:

| Row | Teensy pin |
|:---:|:----------:|
|  1  |     17     |
|  2  |     16     |
|  3  |     15     |
|  4  |     14     |

| Column | Teensy pin |
|:------:|:----------:|
|    1   |      2     |
|    2   |      3     |
|    3   |      4     |
|    4   |      5     |
|    5   |      6     |
|    6   |     12     |
|    7   |     19     |
|    8   |     20     |
|    9   |     21     |
|   10   |     22     |
|   11   |     23     |


Keyboard Maintainer: [You](https://github.com/j-kramer)

Make example for this keyboard (after setting up your build environment):

    make handwired/atreus_teensy32:default

See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.