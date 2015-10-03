#include "main.h"

int main(void) {
  t_player player = {.cur_money = BASE_GAME_GAINS};
  play(&player);

  return 0;
}
