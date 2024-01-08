#include <stdio.h>

char board[3][3];

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void display_board() {
    int i;
    printf("-------------\n");
    for (i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int is_valid_move(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return 0;
    }
    if (board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

int is_board_full() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int check_win() {
    int i;
    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }
    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return 1;
    }
    return 0;
}

void play_game() {
    int row, col, current_player = 1, moves = 0;
    char symbol;

    initialize_board();

    while (1) {
        display_board();

        if (current_player == 1) {
            symbol = 'X';
        } else {
            symbol = 'O';
        }

        printf("Player %d (%c), enter your move (row column): ", current_player, symbol);
        scanf("%d %d", &row, &col);

        if (is_valid_move(row, col)) {
            board[row][col] = symbol;
            moves++;

            if (check_win()) {
                display_board();
                printf("Congratulations! Player %d (%c) wins!\n", current_player, symbol);
                break;
            } else if (is_board_full()) {
                display_board();
                printf("It's a draw!\n");
                break;
            }

            current_player = (current_player % 2) + 1;
        } else {
            printf("Invalid move. Try again.\n");
            // Clear the input buffer to avoid infinite loop in case of invalid input
            while (getchar() != '\n');
        }
    }
}

int main() {
    printf("Welcome to Tic-Tac-Toe!\n");
    play_game();
    return 0;
}
