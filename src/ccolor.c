#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "colors.h"

// Semantic Versioning
int vmajor = 1;
int vminor = 0;
int vpatch = 0;

// Note:
// It is sensible that we can output colors, that's the point!
// However, we can't know if we have more than the basic 8...
// So only the simple eight are allowed on non-user events.

void cli_help(void) {
  colors_green();
  printf("%s%d.%d.%d\n", "Milne's ccolor v", vmajor, vminor, vpatch);
  colors_reset();
  printf("%s", "A tool for printing color to the terminal.\n");
  printf("%s", "---\n");
  colors_red();
  printf("%s", "Warning: ccolor does not check for terminal support.\n");
  colors_reset();
  printf("%s", "---\n");
  printf("%s", "ccolor --help | Show this message and exit.\n");
  printf("%s", "ccolor -h | Show this message and exit.\n");
  colors_green();
  printf("%s", "Useful Options:\n");
  colors_reset();
  printf("%s", "ccolor clear | Clear the terminal.\n");
  printf("%s", "ccolor reset | Remove any formatting options on the terminal.\n");
  colors_green();
  printf("%s", "256bit Colors:\n");
  colors_reset();
  printf("%s", "ccolor 256 [NUM] | Sets the terminal text to NUM.\n");
  colors_green();
  printf("%s", "Extended Colors:\n");
  colors_reset();
  printf("%s", "ccolor bright-black | Sets terminal text color to bright black.\n");
  printf("%s", "ccolor bright-red | Sets terminal text color to bright red.\n");
  printf("%s", "ccolor bright-green | Sets terminal text color to bright green.\n");
  printf("%s", "ccolor bright-yellow | Sets terminal text color to bright yellow.\n");
  printf("%s", "ccolor bright-blue | Sets terminal text color to bright-blue.\n");
  printf("%s", "ccolor bright-magenta | Sets terminal text color to bright magenta.\n");
  printf("%s", "ccolor bright-cyan | Sets terminal text color to bright cyan.\n");
  printf("%s", "ccolor bright-white | Sets terminal text color to bright white.\n");
  colors_green();
  printf("%s", "Basic Colors:\n");
  colors_reset();
  printf("%s", "ccolor black | Sets terminal text color to black.\n");
  printf("%s", "ccolor red | Sets terminal text color to red.\n");
  printf("%s", "ccolor green | Sets terminal text color to green.\n");
  printf("%s", "ccolor yellow | Sets terminal text color to yellow.\n");
  printf("%s", "ccolor blue | Sets terminal text color to blue.\n");
  printf("%s", "ccolor magenta | Sets terminal text color to magenta.\n");
  printf("%s", "ccolor cyan | Sets terminal text color to cyan.\n");
  printf("%s", "ccolor white | Sets terminal text color to white.\n");
}

int main(int argc, char* argv[]) {
  if(argc >= 2) {
    if(strcmp(argv[argc - 1], "--help") == 0 || strcmp(argv[argc - 1], "-h") == 0) {
      cli_help();
      return 0;
    }
    else if(argc == 3 && strcmp(argv[1], "256") == 0) {
      int val = atoi(argv[2]);
      if(val < 0 || val > 256) {
        fcolors_red(stderr);
        fprintf(stderr, "%s%d%s", "The 256 option requires a number between 0 and 256 but received: ", val, "\n");
        fcolors_reset(stderr);
        return -1;
      }
      colors_256(val);
      return 0;
    }
    else if(strcmp(argv[argc - 1], "reset") == 0) {
      colors_reset();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "clear") == 0) {
      colors_clear();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "black") == 0) {
      colors_black();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "red") == 0) {
      colors_red();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "green") == 0) {
      colors_green();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "yellow") == 0) {
      colors_yellow();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "blue") == 0) {
      colors_blue();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "magenta") == 0) {
      colors_magenta();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "cyan") == 0) {
      colors_cyan();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "white") == 0) {
      colors_white();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "bright-black") == 0) {
      colors_bright_black();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "bright-red") == 0) {
      colors_bright_red();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "bright-green") == 0) {
      colors_bright_green();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "bright-yellow") == 0) {
      colors_bright_yellow();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "bright-blue") == 0) {
      colors_bright_blue();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "bright-magenta") == 0) {
      colors_bright_magenta();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "bright-cyan") == 0) {
      colors_bright_cyan();
      return 0;
    }
    else if(strcmp(argv[argc - 1], "bright-white") == 0) {
      colors_bright_white();
      return 0;
    }
    else {
      // Could not find any options, error.
      fcolors_red(stderr);
      fprintf(stderr, "%s%s%s", "Unknown argument: ", argv[argc - 1], "\n");
      fcolors_reset(stderr);
      cli_help();
      return -1;
    }
  }
  else {
    fcolors_red(stderr);
    fprintf(stderr, "%s", "Error: Not Enough Arguments.\n");
    fcolors_reset(stderr);
    cli_help();
    return -1;
  }
}
