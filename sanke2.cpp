#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;


bool gameOver;

const int width = 20;
const int height = 20;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
const int leftMargin = 10;


enum eDirections
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

eDirections dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width + 1;
    fruitY = rand() % height + 1;
    score = 0;
    nTail = 0;
}

void Draw()
{
    system("cls");
    
    cout<<"\n\n\t!!!\tSNAKE GAME\t!!!\n\n";
    
    
     for (int i = 0; i < leftMargin; i++) {
        cout << " ";  // Left margin spaces
    }
    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
    
    for (int i = 1; i <= height; i++)
    {
    	for (int k = 0; k < leftMargin; k++) {
            cout << " ";
        }
        for (int j = 1; j <= width + 1; j++)
        {
            if (j == 1 || j == width + 1)
                std::cout << "#";
            if (i == y && j == x)
            {
                std::cout << "0"; // Head of the snake
            }
            else if (j == fruitX && i == fruitY)
            {
                std::cout << "*"; // Fruit
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "0"; // Body of the snake
                        print = true;
                    }
                }
                if (!print)
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < leftMargin; i++) {
        cout << " ";  // Left margin spaces
    }
    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (dir != RIGHT) dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT) dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN) dir = UP;
            break;
        case 's':
            if (dir != UP) dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x >= width + 1 || x < 1 || y >= height + 1 || y < 1)
    {
        gameOver = true;
        std::cout << "Game Over! You hit the wall." << std::endl;
        return;
    }

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
            std::cout << "Game Over! You hit yourself." << std::endl;
            return;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        nTail++;
        fruitX = rand() % width + 1;
        fruitY = rand() % height + 1;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0))); // Initialize random seed
    Setup();
    while (!gameOver)
    {   
        Draw();
        Input();
        Logic();
        Sleep(200); // Adjust this value to make the game slower or faster
    }
    std::cout << "Game Over! Final Score: " << score << std::endl;
    return 0;
}

