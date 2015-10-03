#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "player.h"

#define BASE_GAME_GAINS 200

/* game.c */
void play(t_player*);

/* readline.c */
char *read_line(void);

/* err.c */
int lconv_error(void);

/* rand.c */
int rand_between(int from, int to);

/* read.c */
long read_long(char* message, long between_from, long between_to);
