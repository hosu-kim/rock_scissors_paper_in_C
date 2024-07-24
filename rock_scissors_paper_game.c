#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// fuction declarations
void clear_screen(void);
int get_user_choice(void);
int get_computer_choice(void);
void display_choices(const char *user_choice, const char *computer_choice);
void display_result(int user_point, int computer_point, const char *message);
void display_final_result(int user_point, int computer_point);
const char *determine_winner(int user_choice, int computer_choice, int *user_point, int *computer_point);

int main(void)
{
    int user_point = 0;
    int computer_point = 0;
    const char *list[3] = {"Rock", "Scissors", "Paper"};

    // Initialize the random number generator with the current time as the seed
    srand(time(NULL));

    clear_screen();
    printf("Welcome to the Rock Scissors Paper game!\n");

    for (int game_over = 0; game_over < 10; game_over++)
    {
        int user_choice = get_user_choice();
        int computer_choice = get_computer_choice;

        clear_screen();
        display_choices(list[user_choice - 1], list[computer_choice - 1]);

        const char *result_message = determine_winner(user_choice, computer_choice, &user_point, &computer_point);
        display_result(user_point, computer_point, result_message);

        printf("(Round: %d/10)\n\n", game_over + 1);
        if (game_over < 9)
        {
            printf("New match starting in 5 seconds...\n");
            sleep(5);
        }
        else
        {
            printf("Game over! Making result\n");
        }
        clear_screen();
    }
        display_final_result(user_point, computer_point);
        return(0);
}

void clear_screen(void)
{
    printf("\e[1;1H\e[2J");
}

int get_user_choice(void)
{
    char input[10];
    while (true)
    {
        printf("Choose one of the numbers (Rock: 1, Scissors: 2, Paper: 3)\nType here: ");
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            // Remove newline character if present
            input[strcspn(input, "\n")] = '\0';
        }
        // Check if the input is a digit and within range
        if (strlen(input) == 1 && isdigit(input[0]))
        {
            int user_choice = input[0] - '0';
            if (user_choice >= 1 && user_choice <=3)
            {
                return user_choice;
            }
        }
        clear_screen();
            printf("Invalid input. Please choose a number between 1 and 3.\n");
    }
}

int get_computer_choice(void)
{
    return rand() % 3 + 1;
}

void display_choices(const char *user_choice, const char *computer_choice)
{
    printf("Your choice: %s\nComputer's choice: %s\n", user_choice, computer_choice);
}

const char *determine_winner(int user_choice, int computer_choice, int *user_point, int *computer_point)
{
    if ((user_choice == 1 && computer_choice == 2) ||
        (user_choice == 2 && computer_choice == 3) ||
        (user_choice == 3 && computer_choice == 1))
    {
        (*user_point)++;
        return "You won! You got one point.";
    }
    else if ((computer_choice == 1 && user_choice == 2) ||
             (computer_choice == 2 && user_choice == 3) ||
             (computer_choice == 3 && user_choice == 1))
    {
        (*computer_point)++;
        return "You lose. :(";
    }
    else
    {
        return "Bang! A tie.";
    }
}

void display_result(int user_point, int computer_point, const char *message)
{
    printf("You: %d vs Computer: %d\n%s\n", user_point, computer_point, message);
}

void display_final_result(int user_point, int computer_point)
{
    printf("-----RESULT-----\nYou: %d vs Computer %d\n", user_point, computer_point);
}
