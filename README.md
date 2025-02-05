Sure! Here's an updated version of the README with a section dedicated to the data structures used in the code:

---

# Snake Game - C++ Console Application

This is a simple Snake game implemented in C++ for the console. It features:
- A snake that moves on a grid.
- A food item that the snake consumes to grow longer.
- Collision detection with the boundaries and the snake itself.
- A scoring system where the score increases by 1 for each piece of food consumed.
- A feature to track the maximum score achieved during multiple game sessions.

## Features

- *Snake Movement*: The snake moves in four directions (up, down, left, right).
- *Score Tracking*: The score increases by 1 when the snake eats food. The max score is recorded across multiple game sessions.
- *Game Over Detection*: The game ends if the snake collides with itself or with the boundaries.
- *Max Score Display*: Displays the highest score achieved in the current session.
- *Key Controls*:
  - 'w' - Move up
  - 's' - Move down
  - 'a' - Move left
  - 'd' - Move right
  - 'x' - Exit the game

## Requirements

- *Platform*: Windows
- *Compiler*: A C++ compiler that supports the C++11 standard or later (e.g., GCC, MSVC).
- *Libraries*:
  - conio.h for input handling (_kbhit() and _getch()).
  - windows.h for Sleep() to control the game's speed.

## How to Compile and Run

### 1. Compile the Game

To compile the Snake game, follow these steps depending on your IDE or compiler:

#### Using GCC (MinGW):
1. Open the Command Prompt (or PowerShell) in the folder where the game file is saved.
2. Use the following command to compile the code:
   bash
   g++ snake_game.cpp -o snake_game.exe
   
3. Run the compiled game:
   bash
   ./snake_game.exe
   

#### Using Visual Studio (MSVC):
1. Open Visual Studio and create a new C++ Console Project.
2. Copy the provided code into your main .cpp file.
3. Build and run the project by pressing *F5*.

### 2. Start the Game
Once the game is compiled and running, follow the on-screen instructions:
- Press any key to start the game.
- Use the *W, **A, **S, **D* keys to control the snake.
- The game will end if the snake collides with itself or the boundaries.
- You can play again by pressing *y* or *Y* after the game ends.

### 3. Score System
- Each time the snake eats food (represented by the $ symbol), the score will increase by 1.
- The game will display the current score and the maximum score achieved during the session.

## Data Structures Used

The following data structures are utilized in the game:

1. **Vector of pairs (std::vector<std::pair<int, int>>):
   - *Used in*: Snake::body, Food::respawn(), and checking for collisions.
   - *Purpose*: This is used to represent the snake's body and store its positions on the grid. Each segment of the snake’s body is a pair of coordinates (x, y), where x is the column position and y is the row position in the grid.
   - *Details*: The snake's body grows when the snake eats food, and the new body part is added at the front of the vector.

2. **Enum Direction**:
   - *Used in*: Snake::dir
   - *Purpose*: The Direction enum is used to track the direction of movement for the snake. It can have one of the following values: STOP, UP, DOWN, LEFT, RIGHT.
   - *Details*: This helps in managing the movement of the snake and preventing it from reversing direction (i.e., from moving UP directly to DOWN).

3. **Integer variables (int):
   - *Used in*: score, maxScore, x, y, and more.
   - *Purpose*: Integers are used to track scores, positions, and the grid size. They also serve to control loops and check for game over conditions.

4. **Static Variable (static int maxScore):
   - *Used in*: Game::maxScore
   - *Purpose*: A static variable that stores the highest score achieved during any game session. It is shared across all instances of the Game class.
   - *Details*: It is used to track the highest score so that it can be updated and displayed after every game session.

5. **Boolean (bool):
   - *Used in*: gameOver, validPosition, isSnake.
   - *Purpose*: Booleans are used to handle logical checks, such as whether the game is over, whether a food position is valid (doesn't overlap with the snake), and to check if a grid space is occupied by the snake's body.

6. **Character (char):
   - *Used in*: For player inputs (e.g., 'w', 'a', 's', 'd', 'x') and rendering the grid (e.g., '0' for the snake and '$' for food).
   - *Purpose*: Characters represent movement commands and are used in the visual output of the game to render different game elements.

7. *Function pointers/Methods*:
   - *Used in*: Movement, collision detection, and input processing.
   - *Purpose*: Methods are used to encapsulate behaviors such as drawing the game grid, handling user input, and checking for collisions. Each method takes appropriate data as input (e.g., snake's body, food's position) and modifies game state accordingly.

### Game Logic

- *Food Respawn*: The Food::respawn() method ensures that food is placed at a valid, empty location on the grid, avoiding overlap with the snake's body.
- *Snake Growth*: When the snake eats food, it "grows" by adding a new segment to its body using the Snake::grow() method, which pushes a copy of the last body segment to the vector.
- *Game Over Check*: The Snake::hasCollided() method checks if the snake collides with itself or the boundaries of the grid.

## Example

### In-game Display:


Press any key to start the game...

Score: 5
Max Score: 5
##############
#            #
#    0       #
#    0       #
#    0       #
#            #
#     $      #
##############

Game Over! Final Score: 5
Play again? (y/n): y

Score: 6
Max Score: 6
##############
#            #
#    0       #
#    0       #
#    0       #
#            #
#     $      #
##############

Game Over! Final Score: 6
Play again? (y/n): n


## Known Issues
- The game currently only works on Windows due to the use of conio.h and windows.h.
- It does not have advanced features like a graphical interface or levels.

## Future Enhancements
- Implement a graphical user interface (GUI) using libraries like SFML or SDL.
- Add different difficulty levels or increasing snake speed.
- Add more food types or power-ups to enhance gameplay.

## License

This project is open-source. Feel free to modify and distribute it as you like!

---

This section now explains the main data structures used in the code, helping users understand how the program works at a deeper level. Let me know if you need any more details or modifications!
