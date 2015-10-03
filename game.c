#include "main.h"

int random_card(void) {
  return rand_between(1, 36);
}

/* compare cards, manages money */
void play_turn(int game_card, t_player* player) {
  printf("Your pick: %i. Game's pick: %i.\n",
      player->cur_card,
      game_card);

  if (game_card == player->cur_card) {
    printf("You won! You got the right card!\n");
    player->cur_money += player->cur_bet * 3;
  } else if ((game_card % 2) == (player->cur_card % 2)) {
    printf("You got the color right! You get back 50%% of your bet!\n");
    player->cur_money += floor(player->cur_bet / 2);
  } else {
    printf("Aw :(! You lost everything! :(.\n");
  }
  player->cur_bet = 0;    
}

int ask_keep_playing() {
  char *read;
  int ret;

  printf("\nDo you want to keep playing? y/n\n");
  read = read_line();
  ret = !strcmp(read, "y");
  printf("\n");
  free(read);
  return ret;
}

void play(t_player* player) {
  print_stats(player);
  do { 
    bet_money(player);
    player->cur_card = (int)read_long("Pick a number", 1, 36);

    play_turn(random_card(), player);
    print_stats(player);
  } while (player->cur_money > 0 && ask_keep_playing());

  player_exit_message(player);
}
