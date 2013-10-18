#ifndef _TICTACTOE_H
#define _TICTACTOE_H

typedef enum {
    EMPTY = 0,
    X = 1,
    O = -1
} player_t;

typedef player_t board_t[9];

player_t winner(board_t field);

#endif /* _TICTACTOE_H */
