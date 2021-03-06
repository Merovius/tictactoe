// vim: noexpandtab
#ifndef _TICTACTOE_H
#define _TICTACTOE_H
#include <stdbool.h>

typedef enum {
	EMPTY = 0,
	X = 1,
	O = -1
} player_t;

typedef player_t board_t[9];

player_t winner(const board_t field);
int make_move(board_t board, player_t player, int move);
int best_move(const board_t board, player_t player);
bool isdraw(const board_t board);

#endif /* _TICTACTOE_H */
