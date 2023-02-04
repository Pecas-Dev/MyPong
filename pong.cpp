#include "raylib.h"
#include <iostream>

using namespace std;

struct LeftPaddle
{
    int leftPaddle_x{10};
    int leftPaddle_y{350};
    int leftPaddle_width{25};
    int leftPaddle_height{125};
    Color leftPaddleColor{WHITE};
};

struct RightPaddle
{
    int rightPaddle_x{965};
    int rightPaddle_y{350};
    int rightPaddle_width{25};
    int rightPaddle_height{125};
    Color rightPaddleColor{WHITE};
};

struct WindowDimensions
{
    int width{1000};
    int height{800};

    // WindowColliders
    int x_min{};
    int X_MAX{};

    int y_min{};
    int Y_MAX{};
};

int main()
{
    LeftPaddle leftPaddle;
    RightPaddle rightPadle;

    int Fps{60};

    InitWindow(1000, 800, "MyPong");

    SetTargetFPS(Fps);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Middle line
        DrawRectangle(490, 0, 10, 850, WHITE);

        // LEFT RECTANGLE
        DrawRectangle(leftPaddle.leftPaddle_x, leftPaddle.leftPaddle_y, leftPaddle.leftPaddle_width, leftPaddle.leftPaddle_height, leftPaddle.leftPaddleColor);

        // RIGHT RECTANGLE
        DrawRectangle(rightPadle.rightPaddle_x, rightPadle.rightPaddle_y, rightPadle.rightPaddle_width, rightPadle.rightPaddle_height, rightPadle.rightPaddleColor);

        EndDrawing();
    }
}