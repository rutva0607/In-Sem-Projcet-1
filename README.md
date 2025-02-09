# Snake Game🐍🐍🐍

## Created By
- **Rutva Mehta**
- **Khush Hingrajiya**
- **Manthan Kanetiya**
- **Vikas Bhabhor**

## Overview
This is a classic Snake Game implemented in C++ using the Windows Console. The game allows the player to control a snake that moves around the screen, eating food to grow longer while avoiding collisions with the walls and itself. The game includes multiple difficulty levels and maintains high scores for each difficulty setting.

## Features
- **Multiple Difficulty Levels**: Choose between Easy, Medium, and Hard, with different snake speeds.
- **Dynamic Rendering**: The game board is efficiently rendered using string manipulation for smooth gameplay.
- **Tail Growth**: The snake's length increases as it consumes food.
- **Collision Detection**: The game ends if the snake collides with the walls or itself.
- **High Score Tracking**: Maintains separate high scores for each difficulty level.
- **User Customization**: Enter your name at the start for a personalized experience.
- **Smooth Input Handling**: Uses `_getch()` for real-time key inputs (WASD controls).

## Data Structures Used
- **Arrays**: Used to store the positions of the snake's tail segments (`tailX[]` and `tailY[]`).
- **Enumerations**: Used for representing directions (`enum Direction`) and difficulty levels (`enum Difficulty`).
- **Strings**: Used for rendering the game board and displaying messages.
- **Boolean Variables**: Used for tracking the game state (e.g., `gameOver`).
- **Integer Variables**: Used to store the snake's position, food position, score, and tail length.
- **Structs (COORD)**: Part of the Windows API, used for cursor manipulation in the console.
- **Pointers (HANDLE)**: Used to interact with the console for setting cursor position and text color.
- **Random Number Generator (`rand()`)**: Used to generate random food positions on the board.
- **Conditional Statements and Loops**: Used for game mechanics, such as checking collisions and updating the snake's position.
- **Queues**: Can be used to optimize the tail movement storage and processing.
- **Maps**: Could be implemented to track player statistics or store additional game settings.

## Display of the Game
The game is displayed in the console using ASCII characters:
```
######################################
#                                    #
#                                    #
#            O                       #
#                                    #
#                                    #
#                                    #
#                                    #
#               $                    #
#                                    #
######################################
Score: 10   |   High Score: 50
```
### Symbols Used
- `O` for the snake's head
- `o` for the snake's tail
- `$` for the food
- `#` for the borders

## Controls
- **W** - Move Up
- **S** - Move Down
- **A** - Move Left
- **D** - Move Right
- **X** - Exit the game

## How to Run
1. Compile the code using a C++ compiler (such as MinGW for Windows).
2. Run the generated executable.
3. Enter your name and select a difficulty level.
4. Use WASD keys to control the snake.
5. Eat food to grow and avoid colliding with walls or yourself.

## Compilation Instructions
Use a C++ compiler that supports Windows API functions.
```sh
 g++ snake_game.cpp -o snake_game.exe
```
Run the executable:
```sh
 ./snake_game.exe
```

## Dependencies
- Windows OS (since it uses `windows.h`, `conio.h`, and console cursor manipulation)
- A C++ compiler (such as MinGW or MSVC)

## Game Mechanics
- The snake starts at the center of the board and remains stationary until a movement key is pressed.
- The food appears randomly, ensuring it does not spawn on the snake.
- The snake grows upon consuming food.
- Collision with the walls or itself results in a game over.
- The player's score is updated and compared to the high score for the chosen difficulty.

## Difficulty Levels
- **Easy**: Slow movement (200ms delay per frame).
- **Medium**: Moderate speed (120ms delay per frame).
- **Hard**: Fast-paced (80ms delay per frame).

## Exit and Replay Options
After a game ends, the player can choose to:
- Replay the same difficulty.
- Return to the main menu to change difficulty.
- Exit the game.

## Known Issues
- The game only works on Windows due to dependencies on `windows.h` and `_getch()`.
- The board size is fixed and may not scale properly on smaller console windows.

## Future Enhancements
- Add support for Linux/Mac using cross-platform libraries.
- Implement an improved rendering system using graphics libraries.
- Add sound effects and animations.
- Introduce power-ups and obstacles for more challenging gameplay.

## License
This project is open-source and free to use for educational and personal projects.

Enjoy the game!

