// vim: noexpandtab
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "tictactoe.h"

#define run_test(name) do { \
	num_tests++; \
	if (test_ ## name ()) { \
		printf("\033[32m%s\033[m\n", #name); \
	} else { \
		num_failed++; \
		printf("\033[31m%s\033[m\n", #name); \
	} \
} while (0)

#define ok(b) do { \
	if (b) { \
		printf("\033[31mExpected: %s\033[m\n", #b); \
		return false; \
	} \
} while (0)

#define ok_eq(a, b) do { \
	if (a != b) { \
		printf("\033[31mExpected: %s == %d, Got: %d\033[m\n", #a, b, a); \
		return false; \
	} \
} while (0)

bool test_winner() {
	#include "test_winner.defs"
	ok_eq(winner(empty_board), EMPTY);
	ok_eq(winner(x_row_1), X);
	ok_eq(winner(o_row_2), O);
	ok_eq(winner(x_row_3), X);
	ok_eq(winner(o_col_1), O);
	ok_eq(winner(x_col_2), X);
	ok_eq(winner(o_col_3), O);
	ok_eq(winner(x_diag_1), X);
	ok_eq(winner(o_diag_2), O);

	return true;
}

bool test_moves() {
	#include "test_moves.defs"
	ok_eq(make_move(board1, X, 0), 0);
	ok_eq(make_move(board1, O, 4), 0);
	ok_eq(make_move(board1, X, 1), 0);
	ok_eq(make_move(board1, O, 2), 0);
	ok_eq(make_move(board1, X, 6), 0);
	ok_eq(make_move(board1, O, 3), 0);
	ok_eq(make_move(board1, X, 5), 0);
	ok_eq(make_move(board1, O, 8), 0);
	ok_eq(make_move(board1, X, 7), 0);
	ok_eq(winner(board1), EMPTY);

	ok_eq(make_move(board2, X, 4), 1);

	return true;
}

bool test_win() {
	#include "test_win.defs"
	ok_eq(best_move(trivial_board, X), 4);
	ok_eq(best_move(trivial_board, O), 4);

	ok_eq(best_move(fork_board, X), 3);

	return true;
}

int main(int argc, char **argv) {
	int num_tests = 0;
	int num_failed = 0;

	run_test(winner);
	run_test(moves);
	run_test(win);

	if (num_failed > 0) {
		printf("\033[1;31m%d of %d tests failed\033[m\n", num_failed, num_tests);
		return 1;
	} else {
		printf("\033[1;32m%d %s ran okay\033[m\n", num_tests, num_tests == 1 ? "test" : "tests");
		return 0;
	}
}
