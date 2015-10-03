#include "main.h"

long read_long(char* message, long between_from, long between_to) {
  char *endptr = NULL;
  char *read;
  /* = 0 to silence clang warning in do{}while(..<-here)
   * as ret will have been initialized OR "!read"(in the while clause) will have stopped the `||`s */
  long ret = 0;

  do {
    if (message) {
      printf("%s (between %li and %li).\n",
          message, between_from, between_to);
    }
    if ((read = read_line())) {
      ret = strtol(read, &endptr, 10);
      free(read);
    }
  } while (!read || *endptr || ret < between_from || ret > between_to);
  return ret;
}
