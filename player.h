typedef struct {
  int cur_card;
  long cur_money;
  long cur_bet;
} t_player;

void print_stats(t_player*);
void bet_money(t_player*);
void player_exit_message(t_player*);
