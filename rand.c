#include <stdlib.h>
#include <time.h>

int rand_between(int from, int to) {
  static int init = 0;

  if (!init) {
    srand((unsigned int)time(NULL));
    init++;
  }
  return (rand() % (to - from + 1)) + from;
}
