# Milne's ccolor

A library and console application for tweaking colors on the console.

---

## Table of Contents

- [Library](#library)
- [CLI Application](#cli-application)
  * [Compiling](#compiling)
    + [Prequisites:](#prequisites-)
    + [Compiling:](#compiling-)
    + [Installing:](#installing-)
  * [Usage](#usage)
- [Platform Support](#platform-support)
- [Colors API](#colors-api)
  * [Usage](#usage-1)
  * [Functions](#functions)
  * [Unstable](#unstable)
- [LICENSE](#license)

---

[![asciinema demo](https://screenshotscdn.firefoxusercontent.com/images/7b46a3e8-c9de-458a-b5b1-c01237826bd6.png)](https://asciinema.org/a/VBflIrV4ImWs2JDtbQt5j6qxJ)

---

# Library

ccolor is a header-only library written in C99.

This means you can copy the file to an include directory and simply link against it.

The Makefile is related to the CLI Application, not the Library.

The file to link against is [src/colors.h](src/colors.h).

i.e. You can do something like:

```
#include <stdio.h>
#include "colors.h"

int main(int argc, char* argv[]) {
  colors_clear();
  colors_bright_blue();
  printf("%s", "Hello, World!\n");
  colors_reset();
}
```

See [Colors API](#colors-api) for full details.

---

# CLI Application

## Compiling

### Prequisites:

* C-Compiler
* make

### Compiling:

Run ```make``` in the top directory of ccolor.

### Installing:

Run ```make install``` in the top directory of ccolor.

## Usage

ccolor sets a color, but does not flush the stdout buffer, except for the reset and clear commands, for both text and background variants.

So a simple script might look like:

```
#!/bin/sh

ccolor clear
ccolor bright-blue
echo 'Hello, World!'
ccolor reset
```

As ccolor is simply outputing ANSI escape codes to stdout, it supports redirection as well.

---

# Platform Support

Linux is fully supported and maintained.

macOS is untested, but should have full support.

Windows is untested, and though ansi.sys should work (as no \*nix specific options have been used), there may be some issues. Feel free to report them, and I'll see what I can do.

---

# Colors API

Colors will be referred to by their ANSI names.

Unless specified, the functions do *not* flush stdout.

## Usage

A quick example:

```
colors_256(4);
printf("%s". "This is blue!\n");
colors_reset();
```

## Functions

```colors_clear(void)``` - Clears the console, this also flushes stdout.

```fcolors_clear(FILE* out)``` - Clears the given file (but doesn't destroy written bits), this also flushes the given file.

```colors_reset(void)``` - This function removes any styling currently on stdout. This also flushes stdout.

```fcolors_reset(FILE* out)``` - This function removes any styling currently on the given file.

```colors_bold(void)``` - Set the text on stdout to bold. Clear this option using ```colors_reset```.

```fcolors_bold(FILE* out)``` - Set the text on the given file to bold. Clear this option using ```fcolors_reset```.

```colors_underline(void)``` - Set the the text on stdout to underlined. Clear this option using ```colors_reset```.

```fcolors_underline(FILE* out)``` - Set the text on the given file to underlined. Clear this option using ```fcolors_reset```.

```colors_blink(void)``` - Set the text on stdout to blinking. (Note: Poor support in modern terminals.) Clear this option using ```colors_reset```.

```fcolors_blink(FILE* out)``` - Set the text on the given file to blinking. (Note: Poor support in modern terminals.) Clear this option using ```fcolors_reset```.

```colors_reversed(void)``` - Set the text to stdout to reversed. Clear this option using ```colors_reset```.

```fcolors_reversed(FILE* out)``` - Set the text on the given file to reversed. Clear this option using ```fcolors_reset```.

```colors_invisible(void)``` - Set the text on stdout to invisible. Clear this option using ```colors_reset```.

```fcolors_invisible(FILE* out)``` - Set the text on the given file to invisible. Clear this option using ```fcolors_reset```.

```colors_256(unsigned int num)``` - This sets the text color on stdout to the given 256bit color. If given an invalid range, it *will* crash using ```assert```.

```fcolors_256(FILE* out, unsigned int num)``` - This sets the text color on the given file to the given 256bit color. If given an invalid range, it *will* crash using ```assert```.

```colors_black(void)``` - This sets the text color on stdout to black.

```fcolors_black(FILE* out)``` - This sets the text color on the given file to black.

```colors_red(void)``` - This sets the text color on stdout to red.

```fcolors_red(FILE* out)``` - This sets the text color on the given file to red.

```colors_green(void)``` - This sets the text color on stdout to green.

```fcolors_green(FILE* out)``` - This sets the text color on the given file to green.

```colors_yellow(void)``` - This sets the text color on stdout to yellow.

```fcolors_yellow(FILE* out)``` - This sets the text color on the given file to yellow.

```colors_blue(void)``` - This sets the text color on stdout to blue.

```fcolors_blue(FILE* out)``` - This sets the text color on the given file to blue.

```colors_magenta(void)``` - This sets the text color on stdout to magenta.

```fcolors_magenta(FILE* out)``` - This sets the text color on the given file to magenta.

```colors_cyan(void)``` - This sets the text color on stdout to cyan.

```fcolors_cyan(FILE* out)``` - This sets the text color on the given file to cyan.

```colors_white(void)``` - This sets the text color on stdout to white.

```fcolors_white(FILE* out)``` - This sets the text color on the given file to white.

```colors_bright_black(void)``` - This sets the text color on stdout to bright black.

```fcolors_bright_black(FILE* out)``` - This sets the text color on the given file to bright black.

```colors_bright_red(void)``` - This sets the text color on stdout to bright red.

```fcolors_bright_red(FILE* out)``` - This sets the text color on the given file to bright red.

```colors_bright_green(void)``` - This sets the text color on stdout to bright green.

```fcolors_bright_green(FILE* out)``` - This sets the text color on the given file to bright green.

```colors_bright_yellow(void)``` - This sets the text color on stdout to bright yellow.

```fcolors_bright_yellow(FILE* out)``` - This sets the text color on the given file to bright yellow.

```colors_bright_blue(void)``` - This sets the text color on stdout to bright blue.

```fcolors_bright_blue(FILE* out)``` - This sets the text color on the given file to bright blue.

```colors_bright_magenta(void)``` - This sets the text color on stdout to bright magenta.

```fcolors_bright_magenta(FILE* out)``` - This sets the text color on the given file to bright magenta.

```colors_bright_cyan(void)``` - This sets the text color on stdout to bright cyan.

```fcolors_bright_cyan(FILE* out)``` - This sets the text color on the given file to bright cyan.

```colors_bright_white(void)``` - This sets the text color on stdout to bright white.

```fcolors_bright_white(FILE* out)``` - This sets the text color on the given file to bright white.

```colors_bg_256(unsigned int num)``` - This sets the background color on stdout to the given 256bit color. If given an invalid range, it *will* crash using ```assert```.

```fcolors_bg_256(FILE* out, unsigned int num)``` - This sets the background color on the given file to the given 256bit color. If given an invalid range, it *will* crash using ```assert```.

```colors_bg_black(void)``` - This sets the background color on stdout to black.

```fcolors_bg_black(FILE* out)``` - This sets the background color on the given file to black.

```colors_bg_red(void)``` - This sets the background color on stdout to red.

```fcolors_bg_red(FILE* out)``` - This sets the background color on the given file to red.

```colors_bg_green(void)``` - This sets the background color on stdout to green.

```fcolors_bg_green(FILE* out)``` - This sets the background color on the given file to green.

```colors_bg_yellow(void)``` - This sets the background color on stdout to yellow.

```fcolors_bg_yellow(FILE* out)``` - This sets the background color on the given file to yellow.

```colors_bg_blue(void)``` - This sets the background color on stdout to blue.

```fcolors_bg_blue(FILE* out)``` - This sets the background color on the given file to blue.

```colors_bg_magenta(void)``` - This sets the background color on stdout to magenta.

```fcolors_bg_magenta(FILE* out)``` - This sets the background color on the given file to magenta.

```colors_bg_cyan(void)``` - This sets the background color on stdout to cyan.

```fcolors_bg_cyan(FILE* out)``` - This sets the background color on the given file to cyan.

```colors_bg_white(void)``` - This sets the background color on stdout to white.

```fcolors_bg_white(FILE* out)``` - This sets the background color on the given file to white.

```colors_bg_bright_black(void)``` - This sets the background color on stdout to bright black.

```fcolors_bg_bright_black(FILE* out)``` - This sets the background color on the given file to bright black.

```colors_bg_bright_red(void)``` - This sets the background color on stdout to bright red.

```fcolors_bg_bright_red(FILE* out)``` - This sets the background color on the given file to bright red.

```colors_bg_bright_green(void)``` - This sets the background color on stdout to bright green.

```fcolors_bg_bright_green(FILE* out)``` - This sets the background color on the given file to bright green.

```colors_bg_bright_yellow(void)``` - This sets the background color on stdout to bright yellow.

```fcolors_bg_bright_yellow(FILE* out)``` - This sets the background color on the given file to bright yellow.

```colors_bg_bright_blue(void)``` - This sets the background color on stdout to bright blue.

```fcolors_bg_bright_blue(FILE* out)``` - This sets the background color on the given file to bright blue.

```colors_bg_bright_magenta(void)``` - This sets the background color on stdout to bright magenta.

```fcolors_bg_bright_magenta(FILE* out)``` - This sets the background color on the given file to bright magenta.

```colors_bg_bright_cyan(void)``` - This sets the background color on stdout to bright cyan.

```fcolors_bg_bright_cyan(FILE* out)``` - This sets the background color on the given file to bright cyan.

```colors_bg_bright_white(void)``` - This sets the background color on stdout to bright white.

```fcolors_bg_bright_white(FILE* out)``` - This sets the background color on the given file to bright white.

## Unstable

These functions can change at any time, and are ***not*** part of the API. However you might find them helpful to run or examine when constructing a program.


``` colors_unstable_show_256(void)``` - This function displays all 512 colors that can be used with ```colors_256```, ```fcolors_256```, ```colors_bg_256```, and ```fcolors_bg_256```.

---

# LICENSE

Milne's ccolor is released under Creative Commons 0 License. This effectively makes it public domain.

See [LICENSE](LICENSE) for full legal code.
