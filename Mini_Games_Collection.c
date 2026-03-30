#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void guessthenumber();
void tictactoe();
void rockpaperscissors();
void hangman();
int main() {
    int pick;
    while (1) {
        printf("\n+--------------------------------------------+\n");
        printf("Welcome to my Game Collection. Have Fun!!\n");
        printf("1. Guess the Number\n");
        printf("2. Tic-Tac-Toe\n");
        printf("3. Rock, Paper, Scissors\n");
        printf("4. Hangman\n");
        printf("5. Exit\n");
        printf("+--------------------------------------------+\n");
        printf("Choose a game you want to play: ");
        scanf("%d", &pick);
        printf("+--------------------------------------------+\n");
        switch (pick) {
            case 1:
                guessthenumber();
                printf("+--------------------------------------------+\n");
                break;
            case 2:
                tictactoe();
                printf("+--------------------------------------------+\n");
                break;
            case 3:
                rockpaperscissors();
                printf("+--------------------------------------------+\n");
                break;
            case 4:
                hangman();
                printf("+--------------------------------------------+\n");
                break;
            case 5:
                printf("See you soon!\n");
                printf("Project by - Asmii Bhati AIDS32\n");
                printf("+--------------------------------------------+\n");
                return 0;
            default:
                printf("Invalid Choice! Please choose a number between 1 to 5.\n");
        }
    }

    return 0;
}

void guessthenumber() {
    int number, attempts = 0, guess;
    const int maxattempt = 7;
    srand(time(0));
    number = rand() % 50 + 1;
    printf("Welcome to Guess the Number!\n");
    printf("Guess the number between 1 to 50:\n");

    while (attempts < maxattempt) {
        scanf("%d", &guess);
        attempts++;
        if (guess > number) {
            printf("Guess a smaller number!\n");
        } else if (guess < number) {
            printf("Guess a bigger number!\n");
        } else {
            printf("You guessed it right! You took %d attempts.\n", attempts);
            return;
        }
    }

    printf("You've reached the maximum limit of attempts. The number was %d.\nBetter luck next time!\n", number);
}

void tictactoe() {
    char board[3][3];
    char player = 'X', computer = 'O';

    void initializeBoard() 
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            };
        }
    }

    void printBoard() {
        printf(" 0 1 2\n");
        for (int i = 0; i < 3; i++) {
            printf("%d ", i);
            for (int j = 0; j < 3; j++) {
                printf("%c", board[i][j]);
                if (j < 2) printf("|");
            }
            printf("\n");
            if (i < 2) printf(" -----\n");
        }
    }

    int checkWin(char symbol) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return 1;
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return 1;
        }
        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return 1;
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return 1;
        return 0;
    }

    int isDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') return 0;
            }
        }
        return 1;
    }

    void playerMove() {
        int row, col;
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
        } else {
            printf("Invalid move. Try again.\n");
            playerMove();
        }
    }

    void computerMove() {
        int row, col;
        srand(time(0));
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (board[row][col] != ' ');

        board[row][col] = computer;
        printf("Computer chose: %d %d\n", row, col);
    }

    initializeBoard();
    while (1) {
        printBoard();
        playerMove();
        if (checkWin(player)) {
            printBoard();
            printf("Player wins!\n");
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }

        computerMove();
        if (checkWin(computer)) {
            printBoard();
            printf("Computer wins!\n");
            break;
        }
        if (isDraw()) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }
}

void rockpaperscissors() {
    char *choice[] = {"Rock", "Paper", "Scissors"};
    int player, computer;
    srand(time(0));
    printf("Welcome to Rock, Paper, Scissors!\n");
    while (1) {
        printf("Enter your choice: 0 for Rock, 1 for Paper, 2 for Scissors: ");
        scanf("%d", &player);

        if (player >= 0 && player <= 2) {
            break;
        } else {
            printf("Invalid choice! Please enter 0 (Rock), 1 (Paper), or 2 (Scissors).\n");
        }
    }

    computer = rand() % 3;
    printf("You chose %s.\nComputer chose %s.\n", choice[player], choice[computer]);

    if (player == computer) {
        printf("It's a tie!\n");
    } else if ((player == 0 && computer == 2) || (player == 1 && computer == 0) || (player == 2 && computer == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

void hangman() {
    const char *list[][2] = {
        {"apple", "I can be red, green, or yellow. You can eat me, but not my core."},
        {"book", "I have pages but I'm not a tree. You read me to learn."},
        {"chair", "Four legs and a back, but I don't walk. You use me to sit and talk."},
        {"dog", "I'm a pet that's man's best friend. I bark! I bite!"},
        {"pencil", "I'm not a pen but I write and draw."},
        {"car", "I have wheels and move fast. I take you places without a past."},
        {"house", "I have a roof and many doors. You live in me!"},
        {"beach", "Sand and sun and sometimes waves. People visit me on holidays."},
        {"movie", "I tell a story with scenes and sound. You watch me while sitting down."},
        {"pizza", "I'm round and cheesy, often with toppings. Once you start eating there is no stopping."}
    };

    int size = sizeof(list) / sizeof(list[0]);
    srand(time(0));
    int random = rand() % size;
const char *word = list[random][0];
    const char *hint = list[random][1];
    int length = strlen(word);
    char guessed[length + 1];
    char guess;
    int attempts = 5, correct = 0;

    for (int i = 0; i < length; i++) {
        guessed[i] = '_';
    }
    guessed[length] = '\0';

    printf("Welcome to Hangman!\n");
    printf("Hint: %s\n", hint);

    while (attempts > 0 && correct < length) {
        printf("Word: %s\n", guessed);
        printf("Attempts left: %d\n", attempts);
        printf("Enter your guess: ");
        scanf(" %c", &guess); // Space before %c ensures no leftover input is read.

        int found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess && guessed[i] == '_') {
                guessed[i] = guess;
                correct++;
                found = 1;
            }
        }

        if (!found) {
            attempts--;
            printf("Oh no! Wrong guess. Guess again.\n");
        }
    }

    if (correct == length) {
        printf("Congratulations! You guessed the word: %s\n", word);
    } else {
        printf("You lost! The word was: %s\nBetter luck next time!\n", word);
    }
}