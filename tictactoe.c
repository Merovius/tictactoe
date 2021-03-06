// vim: noexpandtab
#include <stdint.h>
#include <limits.h>
#include "tictactoe.h"

player_t winner(const board_t board) {
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

static int best_move_impl(board_t board, player_t player, int *rating) {
	int best;
	if (player == X) {
		best = INT_MIN;
	} else {
		best = INT_MAX;
	}

	int best_move = -1;

	for (int i = 0; i < 9; i++) {
		if (board[i] == EMPTY) {
			board[i] = player;
			*rating = winner(board);
			if (*rating == EMPTY) {
				best_move_impl(board, -1 * player, rating);
			}
			if ((player == X && *rating > best) || (player == O && *rating < best)) {
				best = *rating;
				best_move = i;
			}
			board[i] = EMPTY;
		}
	}

	if (best != INT_MIN && best != INT_MAX) {
		*rating = best;
		return best_move;
	}

	*rating = score_board(board);
	return -1;
}

int best_move(const board_t board, player_t player) {
	board_t scratch_board;
	for (int i = 0; i < 9; i++) {
		scratch_board[i] = player * board[i];
	}
	int rating;
	return best_move_impl(scratch_board, X, &rating);
}

bool isdraw(const board_t board) {
	bool full = true;
	for (int i = 0; i < 9; i++) {
		full &= (board[i] != EMPTY);
	}

	return full && (winner(board) == EMPTY);
}
