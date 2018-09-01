#ifndef MILNE_CCOLORS

#include <stdio.h>
#include <assert.h>

// Note: All colors except reset and clear don't flush stdout,
// To maintain normal printf behaviour for end users.

void colors_clear(void) {
  printf("%s", "\x1b[2J\x1b[1;1H");
  // Clear should apply immediately, so flush.
  fflush(stdout);
}

void fcolors_clear(FILE* out) {
  fprintf(out, "%s", "\x1b[2J\x1b[1;1H");
  // Clear should apply immediately, so flush.
  fflush(out);
}

void colors_reset(void) {
  printf("%s", "\x1b[0m");
  // Reset should apply immediately, so flush.
  fflush(stdout);
}

void fcolors_reset(FILE* out) {
  fprintf(out, "%s", "\x1b[0m");
  // Reset should apply immediately, so flush.
  fflush(out);
}

void colors_bold(void) {
  printf("%s", "\x1b[1m");
}

void fcolors_bold(FILE* out) {
  fprintf(out, "%s", "\x1b[1m");
}

void colors_underline(void) {
  printf("%s", "\x1b[4m");
}

void fcolors_underline(FILE* out) {
  fprintf(out, "%s", "\x1b[4m");
}

void colors_blink(void) {
  printf("%s", "\x1b[5m");
}

void fcolors_blink(FILE* out) {
  fprintf(out, "%s", "\x1b[5m");
}

void colors_reversed(void) {
  printf("%s", "\x1b[7m");
}

void fcolors_reversed(FILE* out) {
  fprintf(out, "%s", "\x1b[7m");
}

void colors_invisible(void) {
  printf("%s", "\x1b[8m");
}

void fcolors_invisible(FILE* out) {
  fprintf(out, "%s", "\x1b[8m");
}

void colors_black(void) {
  printf("%s", "\x1b[30m");
}

void fcolors_black(FILE* out) {
  fprintf(out, "%s", "\x1b[30m");
}

void colors_red(void) {
  printf("%s", "\x1b[31m");
}

void fcolors_red(FILE* out) {
  fprintf(out, "%s", "\x1b[31m");
}

void colors_green(void) {
  printf("%s", "\x1b[32m");
}

void fcolors_green(FILE* out) {
  fprintf(out, "%s", "\x1b[32m");
}

void colors_yellow(void) {
  printf("%s", "\x1b[33m");
}

void fcolors_yellow(FILE* out) {
  fprintf(out, "%s", "\x1b[33m");
}

void colors_blue(void) {
  printf("%s", "\x1b[34m");
}

void fcolors_blue(FILE* out) {
  fprintf(out, "%s", "\x1b[34m");
}

void colors_magenta(void) {
  printf("%s", "\x1b[35m");
}

void fcolors_magenta(FILE* out) {
  fprintf(out, "%s", "\x1b[35m");
}

void colors_cyan(void) {
  printf("%s", "\x1b[36m");
}

void fcolors_cyan(FILE* out) {
  fprintf(out, "%s", "\x1b[36m");
}

void colors_white(void) {
  printf("%s", "\x1b[37m");
}

void fcolors_white(FILE* out) {
  fprintf(out, "%s", "\x1b[37m");
}

void colors_bright_black(void) {
  printf("%s", "\x1b[30;1m");
}

void fcolors_bright_black(FILE* out) {
  fprintf(out, "%s", "\x1b[30;1m");
}

void colors_bright_red(void) {
  printf("%s", "\x1b[31;1m");
}

void fcolors_bright_red(FILE* out) {
  fprintf(out, "%s", "\x1b[31;1m");
}

void colors_bright_green(void) {
  printf("%s", "\x1b[32;1m");
}

void fcolors_bright_green(FILE* out) {
  fprintf(out, "%s", "\x1b[32;1m");
}

void colors_bright_yellow(void) {
  printf("%s", "\x1b[33;1m");
}

void fcolors_bright_yellow(FILE* out) {
  fprintf(out, "%s", "\x1b[33;1m");
}

void colors_bright_blue(void) {
  printf("%s", "\x1b[34;1m");
}

void fcolors_bright_blue(FILE* out) {
  printf("%s", "\x1b[34;1m");
}

void colors_bright_magenta(void) {
  printf("%s", "\x1b[35;1m");
}

void fcolors_bright_magenta(FILE* out) {
  fprintf(out, "%s", "\x1b[35;1m");
}

void colors_bright_cyan(void) {
  printf("%s", "\x1b[36;1m");
}

void fcolors_bright_cyan(FILE* out) {
  fprintf(out, "%s", "\x1b[36;1m");
}

void colors_bright_white(void) {
  printf("%s", "\x1b[37m;1");
}

void fcolors_bright_white(FILE* out) {
  fprintf(out, "%s", "\x1b[37m;1");
}

void colors_256(unsigned int num) {
  assert(num < 256);
  printf("%s%d%s", "\x1b[38;5;", num, "m");
}

void fcolors_256(FILE* out, unsigned int num) {
  assert(num < 256);
  fprintf(out, "%s%d%s", "\x1b[38;5;", num, "m");
}

void colors_bg_256(unsigned int val) {
  assert(val < 256);
  printf("%s%d%s", "\x1b[48;5;", val, "m");
}

void fcolors_bg_256(FILE* out, unsigned int val) {
  assert(val < 256);
  fprintf(out, "%s%d%s", "\x1b[48;5;", val, "m");
}

void colors_bg_black(void) {
  printf("%s", "\x1b[40m");
}

void fcolors_bg_black(FILE* out) {
  fprintf(out, "%s", "\x1b[40m");
}

void colors_bg_red(void) {
  printf("%s", "\x1b[41m");
}

void fcolors_bg_red(FILE* out) {
  fprintf(out, "%s", "\x1b[41m");
}

void colors_bg_green(void) {
  printf("%s", "\x1b[42m");
}

void fcolors_bg_green(FILE* out) {
  fprintf(out, "%s", "\x1b[42m");
}

void colors_bg_yellow(void) {
  printf("%s", "\x1b[43m");
}

void fcolors_bg_yellow(FILE* out) {
  fprintf(out, "%s", "\x1b[43m");
}

void colors_bg_blue(void) {
  printf("%s", "\x1b[44m");
}

void fcolors_bg_blue(FILE* out) {
  fprintf(out, "%s", "\x1b[44m");
}

void colors_bg_magenta(void) {
  printf("%s", "\x1b[45m");
}

void fcolors_bg_magenta(FILE* out) {
  fprintf(out, "%s", "\x1b[45m");
}

void colors_bg_cyan(void) {
  printf("%s", "\x1b[46m");
}

void fcolors_bg_cyan(FILE* out) {
  fprintf(out, "%s", "\x1b[46m");
}

void colors_bg_white(void) {
  printf("%s", "\x1b[47m");
}

void fcolors_bg_white(FILE* out) {
  fprintf(out, "%s", "\x1b[47m");
}

void colors_bg_bright_black(void) {
  printf("%s", "\x1b[40;1m");
}

void fcolors_bg_bright_black(FILE* out) {
  fprintf(out, "%s", "\x1b[40;1m");
}

void colors_bg_bright_red(void) {
  printf("%s", "\x1b[41;1m");
}

void fcolors_bg_bright_red(FILE* out) {
  fprintf(out, "%s", "\x1b[41;1m");
}

void colors_bg_bright_green(void) {
  printf("%s", "\x1b[42;1m");
}

void fcolors_bg_bright_green(FILE* out) {
  fprintf(out, "%s", "\x1b[42;1m");
}

void colors_bg_bright_yellow(void) {
  printf("%s", "\x1b[43;1m");
}

void fcolors_bg_bright_yellow(FILE* out) {
  fprintf(out, "%s", "\x1b[43;1m");
}

void colors_bg_bright_blue(void) {
  printf("%s", "\x1b[44;1m");
}

void fcolors_bg_bright_blue(FILE* out) {
  fprintf(out, "%s", "\x1b[44;1m");
}

void colors_bg_bright_magenta(void) {
  printf("%s", "\x1b[45;1m");
}

void fcolors_bg_bright_magenta(FILE* out) {
  fprintf(out, "%s", "\x1b[45;1m");
}

void colors_bg_bright_cyan(void) {
  printf("%s", "\x1b[46;1m");
}

void fcolors_bg_bright_cyan(FILE* out) {
  fprintf(out, "%s", "\x1b[46;1m");
}

void colors_bg_bright_white(void) {
  printf("%s", "\x1b[47;1m");
}

void fcolors_bg_bright_white(FILE* out) {
  fprintf(out, "%s", "\x1b[47;1m");
}

// This is just a helper function,
// to help you work out what color you might like to use.
// Don't depend on it's behaviour staying the same.
void colors_unstable_show_256(void) {
  for(int i = 0; i < 256; i++) {
    colors_256(i);
    printf("%d\n", i);
    colors_reset();
  }
  for(int i = 0; i < 256; i++) {
    colors_bg_256(i);
    printf("%d\n", i);
    colors_reset();
  }
}

#define MILNE_CCOLORS
#endif
