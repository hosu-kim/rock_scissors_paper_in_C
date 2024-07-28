# Rock Scissors Paper Game

Welcome to the Rock Scissors Paper game! This is a simple command-line game where you play Rock-Scissors-Paper against the computer.

## How to Play

1. The game consists of 10 rounds.
2. In each round, you will be prompted to choose one of the three options: Rock, Scissors, or Paper.
3. The computer will also make its choice randomly.
4. After each round, the result will be displayed, showing whether you won, lost, or if it was a tie.
5. The current score will be displayed after each round.
6. After 10 rounds, the final result will be shown, and you will be asked if you want to play again.

## Choices

- Rock: 1
- Scissors: 2
- Paper: 3

## Compiling and Running the Game

### Prerequisites

You need to have a C compiler installed on your machine. For example, you can use `gcc`.

### Compilation

To compile the game, open your terminal and navigate to the directory where the source code is located. Run the following command:

```sh
gcc -o rock_scissors_paper rock_scissors_paper.c
```
### Running the Game
After compiling the game, you can run it by executing:
```sh
./rock_scissors_paper
```
## Code Overview
### Functions
- **`clear_screen()`**: Clears the terminal screen.
- **`get_user_choice()`**: Prompts the user for their choice and validates the input.
- **`get_computer_choice()`**: Generates a random choice for the computer.
- **`display_choices(const char *user_choice_str, const char *computer_choice_str)`**: Displays the choices made by the user and the computer.
- **`display_score(int user_point, int computer_point, int round)`**: Displays the current score and the round number.
- **`display_result(const char *message)`**: Displays the result of the current round.
- **`display_final_result(int user_point, int computer_point)`**: Displays the final result after 10 rounds.
- **`determine_winner(int user_choice, int computer_choice, int *user_point, int *computer_point)`**: Determines the winner of the current round and updates the scores.
- **`user_choice_to_restart()`**: Prompts the user to choose whether to restart or end the game and validates the input.
### Main Loop
The main loop of the game is structured as follows:
1. Initialize the random number generator.
2. Display a welcome message.
3. Loop to play the game until the user chooses to end it.
   - Reset the scores at the beginning of each new game.
   - Loop through 10 rounds, getting the user's and computer's choices, displaying the results, and updating the scores.
   - After 10 rounds, display the final result and prompt the user to choose whether to restart or end the game.
## Author
This game was created by Hosu Kim.
## License
This project is licensed under the MIT License.

