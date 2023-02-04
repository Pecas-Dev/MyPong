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
    int x_min{10};
    int X_MAX{965};

    int y_min{10};
    int Y_MAX{665};
};

int main()
{
    LeftPaddle leftPaddle;
    RightPaddle rightPadle;
    WindowDimensions windowDimensions;

    int paddlesSpeed = 10;

    int Fps{60};

    InitWindow(windowDimensions.width, windowDimensions.height, "MyPong");

    SetTargetFPS(Fps);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Middle line
        DrawRectangle(490, 0, 10, 850, WHITE);

        // LEFT RECTANGLE
        DrawRectangle(leftPaddle.leftPaddle_x, leftPaddle.leftPaddle_y, leftPaddle.leftPaddle_width, leftPaddle.leftPaddle_height, leftPaddle.leftPaddleColor);

        // LEFT PADDLE MOVEMENT
        if (leftPaddle.leftPaddle_y >= windowDimensions.y_min)
        {
            if (IsKeyDown(KEY_UP))
            {
                leftPaddle.leftPaddle_y -= paddlesSpeed;
            }
        }

        if (leftPaddle.leftPaddle_y <= windowDimensions.Y_MAX)
        {
            if (IsKeyDown(KEY_DOWN))
            {
                leftPaddle.leftPaddle_y += paddlesSpeed;
            }
        }

        // RIGHT RECTANGLE
        DrawRectangle(rightPadle.rightPaddle_x, rightPadle.rightPaddle_y, rightPadle.rightPaddle_width, rightPadle.rightPaddle_height, rightPadle.rightPaddleColor);

        // RIGHT PADDLE MOVEMENT
        if (rightPadle.rightPaddle_y >= windowDimensions.y_min)
        {
            if (IsKeyDown(KEY_W))
            {
                rightPadle.rightPaddle_y -= paddlesSpeed;
            }
        }

        if (rightPadle.rightPaddle_y >= windowDimensions.Y_MAX)
        {
            if (IsKeyDown(KEY_S))
            {
                rightPadle.rightPaddle_y += paddlesSpeed;
            }
        }

        EndDrawing();
    }
}