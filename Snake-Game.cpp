#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int WIDTH = 40;
int HEIGHT = 20;
enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
enum Difficulty { EASY, MEDIUM, HARD };
int highScoreEasy = 0;
int highScoreMedium = 0;
int highScoreHard = 0;
void setColor(WORD color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
class SnakeGame {
private:
    bool gameOver;
    int score;
    int x, y;              
    int foodX, foodY;      
    int tailX[100], tailY[100];  
    int tailLength;        
    Direction dir;        
    Difficulty diff;     
    HANDLE console;
    void setCursorPosition(int posX, int posY) {
        COORD coord;
        coord.X = posX;
        coord.Y = posY;
        SetConsoleCursorPosition(console, coord);
    }
    bool isFoodOnSnake(int fx, int fy) {
        if (fx == x && fy == y)
            return true;
        for (int i = 0; i < tailLength; i++) {
            if (tailX[i] == fx && tailY[i] == fy)
                return true;
        }
        return false;
    }
    void spawnFood() {
        do {
            foodX = rand() % WIDTH;
            foodY = rand() % HEIGHT;
        } while (isFoodOnSnake(foodX, foodY));
    }
    void updateHighScore() {
        if (diff == EASY && score > highScoreEasy)
            highScoreEasy = score;
        else if (diff == MEDIUM && score > highScoreMedium)
            highScoreMedium = score;
        else if (diff == HARD && score > highScoreHard)
            highScoreHard = score;
    }
    
public:
    SnakeGame(Difficulty d) : diff(d) {
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        resetGame();
    }
    void resetGame() {
        gameOver = false;
        score = 0;
        dir = STOP; 
        x = WIDTH / 2;
        y = HEIGHT / 2;
        tailLength = 0;
        spawnFood();
    }
    void draw() {
        string output;
        for (int i = 0; i < WIDTH + 2; i++)
            output += "#";
        output += "\n";
        
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (j == 0)
                    output += "#"; 
                if (i == y && j == x) {
                    output += (gameOver ? "x" : "O");
                }
                else if (i == foodY && j == foodX) {
                    output += "$";
                }
                else {
                    bool printed = false;
                    for (int k = 0; k < tailLength; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            output += (gameOver ? "x" : "o");
                            printed = true;
                            break;
                        }
                    }
                    if (!printed)
                        output += " ";
                }
                
                if (j == WIDTH - 1)
                    output += "#"; 
            }
            output += "\n";
        }
        for (int i = 0; i < WIDTH + 2; i++)
            output += "#";
        output += "\n";
        output += "  Score: " + to_string(score) + "    |    High Score: ";
        if (diff == EASY)
            output += to_string(highScoreEasy);
        else if (diff == MEDIUM)
            output += to_string(highScoreMedium);
        else
            output += to_string(highScoreHard);
        output += "\n";

        setCursorPosition(0, 0);
        cout << output;
    }
    void input() {
        if (_kbhit()) {
            char ch = _getch();
            switch (ch) {
                case 'w': if (dir != DOWN)  dir = UP;    break;
                case 's': if (dir != UP)    dir = DOWN;  break;
                case 'a': if (dir != RIGHT) dir = LEFT;  break;
                case 'd': if (dir != LEFT)  dir = RIGHT; break;
                case 'x': gameOver = true;             break;
            }
        }
    }
    void logic() {
        int prevX = tailX[0], prevY = tailY[0], prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;
        for (int i = 1; i < tailLength; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir) {
            case UP:    y--; break;
            case DOWN:  y++; break;
            case LEFT:  x--; break;
            case RIGHT: x++; break;
            default: break;
        }
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            gameOver = true;
            return;
        }
        for (int i = 0; i < tailLength; i++) {
            if (tailX[i] == x && tailY[i] == y) {
                gameOver = true;
                return;
            }
        }
        
        if (x == foodX && y == foodY) {
            score += 10;
            tailLength++;
            spawnFood();
        }
        
        updateHighScore();
    }

    bool isGameOver() {
        return gameOver;
    }
    void delay(int ms) {
        Sleep(ms);
    }
    int getScore() {
        return score;
    }
};
int main() {
    srand(time(0));
    string userName;
    system("cls");
    setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Welcome to the Snake Game!\n";
    cout << "Please enter your name: ";
    getline(cin, userName);
    if (userName.empty()) {
        userName = "Player";
    }
    
    bool exitGame = false;
    while (!exitGame) {
        system("cls");
        setColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "==============================================\n";
        cout << "         WELCOME " << userName << " TO SNAKE GAME!\n";
        cout << "==============================================\n";
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "Select Difficulty Level:\n";
        cout << "  a) Easy    (200ms delay)\n";
        cout << "  b) Medium  (120ms delay)\n";
        cout << "  c) Hard    (80ms delay)\n";
        cout << "  x) Exit\n";
        cout << "==============================================\n";
        cout << "Enter your choice: ";
        char diffInput;
        cin >> diffInput;
        
        Difficulty currentDiff;
        int delayTime = 200;
        if (diffInput == 'a' || diffInput == 'A') {
            currentDiff = EASY;
            delayTime = 200;
        } else if (diffInput == 'b' || diffInput == 'B') {
            currentDiff = MEDIUM;
            delayTime = 120;
        } else if (diffInput == 'c' || diffInput == 'C') {
            currentDiff = HARD;
            delayTime = 80;
        } else if (diffInput == 'x' || diffInput == 'X') {
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
            Sleep(1000);
            continue;
        }
        
        bool backToMenu = false;
        while (!backToMenu && !exitGame) {
            SnakeGame game(currentDiff);
            system("cls");
            setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "\nHello " << userName << ", get ready to play!\n";
            cout << "Press any key to start the game...";
            _getch();
            while (!game.isGameOver()) {
                game.draw();
                game.input();
                game.logic();
                game.delay(delayTime);
            }
            game.draw();
            setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "==============================================\n";
            cout << "              GAME OVER, " << userName << "!\n";
            cout << "         Final Score: " << game.getScore() << "\n";
            cout << "==============================================\n";
            setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << "Press 'p' to play again, 'm' for Main Menu, or 'x' to Exit: ";
            char postChoice;
            cin >> postChoice;
            if (postChoice == 'p' || postChoice == 'P') {
                continue;  
            } else if (postChoice == 'm' || postChoice == 'M') {
                backToMenu = true;
            } else if (postChoice == 'x' || postChoice == 'X') {
                exitGame = true;
                break;
            }
        }
    }
    
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}
