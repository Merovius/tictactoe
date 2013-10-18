#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "tictactoe.h"

int get_move(board_t board) {
    printf("\033[u");
    print_board(board);

    while (1) {
        printf("Choose a position [1-9]: \033[K");
        int choice;
        scanf("%d", &choice);
        if (choice < 1 || choice > 9) {
            continue;
        }
        choice--;
        if (board[choice] == EMPTY) {
            return choice;
        }
    }
}

void print_board(const board_t board) {
	#define SYM(i) (board[i] == X ? "\033[1;32mX\033[m" : board[i] == O ? "\033[1;34mO\033[m" : " ")
	printf("\033[1;30m1\033[m  │\033[1;30m2\033[m  │\033[1;30m3\033[m  \n");
	printf(" %s │ %s │ %s \n", SYM(0), SYM(1), SYM(2));
	printf("   │   │   \n");
	printf("───┼───┼───\n");
	printf("\033[1;30m4\033[m  │\033[1;30m5\033[m  │\033[1;30m6\033[m  \n");
	printf(" %s │ %s │ %s \n", SYM(3), SYM(4), SYM(5));
	printf("   │   │   \n");
	printf("───┼───┼───\n");
	printf("\033[1;30m7\033[m  │\033[1;30m8\033[m  │\033[1;30m9\033[m  \n");
	printf(" %s │ %s │ %s \n", SYM(6), SYM(7), SYM(8));
	printf("   │   │   \n");
	#undef SYM
}

int main() {
    board_t board = { 0, };
    player_t current = X;
    player_t human = X;

    printf("\033[H\033[2JWhat player do you want to be? [X/O] ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'O') {
        choice = 'O';
    }
    printf("Playing as %c\n\n\033[s", choice);
    human = choice == 'X' ? X : O;
    while (1) {
        int move = (current == human ? get_move(board) : best_move(board, current));

        assert(!make_move(board, current, move));

        printf("\033[u");
        print_board(board);


        player_t won = winner(board);
        if (won != EMPTY) {
            printf("\nGame over. You %s\n", won == human ? "won!" : "lost!");
            return 0;
        }

        if (isdraw(board)) {
            printf("\nDraw!\n");
            return 0;
        }

        current *= -1;
    }
}
