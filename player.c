#include "main.h"

void print_stats(t_player* player) {
  printf("Your money: %li$.\n",
      player->cur_money);
}

void bet_money(t_player* player) {
  player->cur_bet = read_long("How much do you wanna bet?",
      1, player->cur_money);

  /* while betting, it's not your money anymore */
  player->cur_money -= player->cur_bet;
}

void player_exit_message(t_player* player) {
  if (player->cur_money < 1) {
    printf("Whoops! You're too poor to play. Sorry!\n");
  } else {
    /* we decided to exit */
    printf("See ya later! Enjoy 'em sweet %li dollar(s)!\n",
        player->cur_money);
  }
}
