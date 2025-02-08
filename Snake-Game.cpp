#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>   
#include <windows.h> 

using namespace std;

const int GRID_SIZE = 20; 
const char SNAKE_BODY = '0';
const char FOOD = '$';
const char EMPTY = ' ';

enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };

class Food {
public:
    int x, y;

    Food(int gridSize) {
        vector< pair<int, int> > v;
        respawn(gridSize, v); 
    }

    void respawn(int gridSize, const vector< pair<int, int> > &snakeBody) {
        bool validPosition = false;
        while (!validPosition) {
            x = rand() % (gridSize - 2) + 1;
            y = rand() % (gridSize - 2) + 1;
            validPosition = true;
            for (const auto &segment : snakeBody) {
                if (segment.first == x && segment.second == y) {
                    validPosition = false;
                    break;
                }
            }
        }
    }
};

class Snake {
public:
    vector< pair<int, int> > body;
    Direction dir;

    Snake() {
        dir = STOP;
        body.push_back(make_pair(GRID_SIZE / 2, GRID_SIZE / 2));
    }

    void move() {
        pair<int, int> head = body[0];
        switch (dir) {
        case UP:    head.second--; break;
        case DOWN:  head.second++; break;
        case LEFT:  head.first--; break;
        case RIGHT: head.first++; break;
        default: break;
        }

      
        body.insert(body.begin(), head);
        body.pop_back();
    }

    void grow() {
        body.push_back(body.back());
    }

    bool hasCollided() {
        
        for (size_t i = 1; i < body.size(); ++i) {
            if (body[i] == body[0]) return true;
        }

        
        return body[0].first < 0 || body[0].second < 0 ||
               body[0].first >= GRID_SIZE || body[0].second >= GRID_SIZE;
    }
};

class Game {
private:
    Snake snake;
    Food food;
    int score;
    bool gameOver;
    static int maxScore; 

public:
    Game() : food(GRID_SIZE), score(0), gameOver(false) {
        food.respawn(GRID_SIZE, snake.body); 
    }

    void draw() {
        system("cls");

        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (i == 0 || i == GRID_SIZE - 1 || j == 0 || j == GRID_SIZE - 1) {
                    cout << "#"; 
                } else {
                    bool isSnake = false;
                    for (const auto &segment : snake.body) {
                        if (segment.first == j && segment.second == i) {
                            cout << SNAKE_BODY;
                            isSnake = true;
                            break;
                        }
                    }
                    if (food.x == j && food.y == i) {
                        cout << FOOD;
                    } else if (!isSnake) {
                        cout << EMPTY;
                    }
                }
            }
            cout << endl;
        }
        cout << "\nScore: " << score << endl;
        cout << "Max Score: " << maxScore << endl; 
    }
    
    void input() {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
            case 'w': if (snake.dir != DOWN) snake.dir = UP; break;
            case 's': if (snake.dir != UP) snake.dir = DOWN; break;
            case 'a': if (snake.dir != RIGHT) snake.dir = LEFT; break;
            case 'd': if (snake.dir != LEFT) snake.dir = RIGHT; break;
            case 'x': gameOver = true; break; 
            }
        }
    }

    void logic() {
        
        if (snake.body[0].first == food.x && snake.body[0].second == food.y) {
            score++;  // Increment score by 1 for each food eaten
            snake.grow();
            food.respawn(GRID_SIZE, snake.body);
        }
        snake.move();
        if (snake.hasCollided()) {
            gameOver = true;
        }
    }

    void run() {
        cout << "Press any key to start the game...";
        _getch(); 

        while (!gameOver) {
            draw();
            input();
            logic();
            Sleep(100);
        }

        if (score > maxScore) {
            maxScore = score;
        }

        cout << "Game Over! Final Score: " << score << endl;
    }

    static int getMaxScore() {
        return maxScore;
    }
};
int Game::maxScore = 0;

int main() {
    char choice;
    do {
        srand(time(0)); 
        Game game;
        game.run();
        cout << "Play again? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}
