// vim: noexpandtab
#include <stdint.h>
#include <limits.h>
#include "tictactoe.h"

player_t winner(board_t board) {
	player_t a, b;

#define _eq_3(a,b,c) ((board[(a)] == board[(b)]) && (board[(b)] == board[(c)]) && (board[(a)] != EMPTY))

	for (int i = 0; i < 3; i++) {
		if (_eq_3(3*i, 3*i+1, 3*i+2)) {
			return board[3*i];
		}

		if (_eq_3(i, i+3, i+6)) {
			return board[i];
		}
	}

	if (_eq_3(0, 4, 8)) {
		return board[4];
	}

	if (_eq_3(2, 4, 6)) {
		return board[4];
	}

	return EMPTY;
#undef _eq_3
}

int score_board(board_t board) {
	return winner(board);
}

int make_move(board_t board, player_t player, int move) {
	if (board[move] != EMPTY) {
		return 1;
	}
	board[move] = player;
	return 0;
}
