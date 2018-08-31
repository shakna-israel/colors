#ifndef MILNE_CCOLORS

#include <stdio.h>
#include <assert.h>

// Note: All colors except reset and clear don't flush stdout,
// To maintain normal printf behaviour for end users.

void colors_clear(void) {
  printf("%s", "\x1b[2J\x1b[1;1H");
  fflush(stdout);
}

void colors_reset(void) {
  printf("%s", "\x1b[0m");
  // Reset should apply immediately, so flush.
  fflush(stdout);
}

void fcolors_reset(FILE* out) {
  fprintf(out, "%s", "\x1b[0m");
  fflush(out);
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

// This is just a helper function,
// to help you work out what color you might like to use.
// Don't depend on it's behaviour staying the same.
void colors_unstable_show_256(void) {
  for(int i = 0; i < 256; i++) {
    colors_256(i);
    printf("%d\n", i);
    colors_reset();
  }
}

#define MILNE_CCOLORS
#endif
