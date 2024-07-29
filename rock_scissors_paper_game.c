/* 
    Rock Scissors Paper Game
    by Hosu Kim
    July 29, 2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

// Function declarations
void clear_screen(void);
int get_user_choice(void);
int get_computer_choice(void);
void display_choices(const char *user_choice_str, const char *computer_choice_str);
void display_score(int user_point, int computer_point, int round);
void display_result(const char *message);
void display_final_result(int user_point, int computer_point);
const char *determine_winner(int user_choice, int computer_choice, int *user_point, int *computer_point);
char user_choice_to_restart();

int main(void)
{
    const char *list[3] = {"Rock", "Scissors", "Paper"};
    char restart = 'R';

    // Initialize the random number generator with the current time as the seed
    srand(time(NULL));

    clear_screen();
    printf("Welcome to the Rock Scissors Paper game!\n");

    while (restart == 'R')
    {
        int user_point = 0;
        int computer_point = 0;

        for (int round = 0; round < 10; round++)
        {
            int user_choice = get_user_choice();
            int computer_choice = get_computer_choice();

            clear_screen();

            display_score(user_point, computer_point, round + 1);
            display_choices(list[user_choice - 1], list[computer_choice - 1]);
            const char *result_message = determine_winner(user_choice, computer_choice, &user_point, &computer_point);
            display_result(result_message);

            if (round < 9)
            {
                printf("\nNew game starting in 5 seconds...\n");
                sleep(5);
                clear_screen();
            }
        }

        display_final_result(user_point, computer_point);
        restart = user_choice_to_restart();
        clear_screen();
    }
    return 0;
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
            if (user_choice >= 1 && user_choice <= 3)
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

void display_choices(const char *user_choice_str, const char *computer_choice_str)
{
    printf("-----Current result-----\nYour choice: %s vs Computer's choice: %s\n", user_choice_str, computer_choice_str);
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

void display_score(int user_point, int computer_point, int round)
{
    printf("You: %d vs Computer: %d (round: %d/10)\n", user_point, computer_point, round);
}

void display_result(const char *message)
{
    printf("%s\n", message);
}

void display_final_result(int user_point, int computer_point)
{
    printf("-----FINAL RESULT-----\nYou: %d vs Computer: %d\n", user_point, computer_point);
}

char user_choice_to_restart()
{
    char input[10];
    while (true)
    {
        printf("Want to play again?\nPress 'R' to restart or 'E' to end the game: ");
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            // Remove newline character if present
            input[strcspn(input, "\n")] = '\0';
        }

        // Convert to uppercase to handle 'r' or 'e'
        if (strlen(input) == 1)
        {
            char restart = toupper(input[0]);
            if (restart == 'R' || restart == 'E')
            {
                return restart;
            }
        }

        printf("Invalid input. Please press 'R' to restart or 'E' to end the game.\n");
    }
}
