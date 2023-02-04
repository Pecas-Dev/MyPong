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

    // Left Paddle Edges
    int LeftPoint_LeftPaddle_X{leftPaddle_x};
    int RightPoint_LeftPaddle_X{leftPaddle_x + leftPaddle_width};
    int UpperPoint_LeftPaddle_Y{leftPaddle_y};
    int BottomPoint_LeftPaddle_Y{leftPaddle_y + leftPaddle_height};
};

struct RightPaddle
{
    int rightPaddle_x{965};
    int rightPaddle_y{350};
    int rightPaddle_width{25};
    int rightPaddle_height{125};
    Color rightPaddleColor{WHITE};

    // Right Paddle Edges
    int LeftPoint_RightPaddle_X{rightPaddle_x};
    int RightPoint_RightPaddle_X{rightPaddle_x + rightPaddle_width};
    int UpperPoint_RightPaddle_Y{rightPaddle_y};
    int BottomPoint_RightPaddle_Y{rightPaddle_y + rightPaddle_height};
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

struct Ball
{
    int ball_x{495};
    int ball_y{400};
    int ballRadius{32};
    Color ballColor{WHITE};

    // Ball Edges
    int Left_Circle_X{ball_x - ballRadius};
    int Right_Circle_X{ball_x + ballRadius};
    int Upper_Circle_Y{ball_y + ballRadius};
    int Bottom_Circle_Y{ball_y - ballRadius};
};

int main()
{
    LeftPaddle leftPaddle;
    RightPaddle rightPadle;
    Ball ball;
    WindowDimensions windowDimensions;

    int paddlesSpeed = 10;
    int ballSpeed = 5;

    int Fps{60};

    InitWindow(windowDimensions.width, windowDimensions.height, "MyPong");

    SetTargetFPS(Fps);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // Middle line
        DrawRectangle(494, 0, 6, 850, WHITE);
        //

        // LEFT RECTANGLE
        DrawRectangle(leftPaddle.leftPaddle_x, leftPaddle.leftPaddle_y, leftPaddle.leftPaddle_width, leftPaddle.leftPaddle_height, leftPaddle.leftPaddleColor);

        // LEFT PADDLE MOVEMENT
        if (leftPaddle.leftPaddle_y >= windowDimensions.y_min)
        {
            if (IsKeyDown(KEY_W))
            {
                leftPaddle.leftPaddle_y -= paddlesSpeed;
            }
        }

        if (leftPaddle.leftPaddle_y <= windowDimensions.Y_MAX)
        {
            if (IsKeyDown(KEY_S))
            {
                leftPaddle.leftPaddle_y += paddlesSpeed;
            }
        }

        // RIGHT RECTANGLE
        DrawRectangle(rightPadle.rightPaddle_x, rightPadle.rightPaddle_y, rightPadle.rightPaddle_width, rightPadle.rightPaddle_height, rightPadle.rightPaddleColor);

        // RIGHT PADDLE MOVEMENT
        if (rightPadle.rightPaddle_y >= windowDimensions.y_min)
        {
            if (IsKeyDown(KEY_UP))
            {
                rightPadle.rightPaddle_y -= paddlesSpeed;
            }
        }

        if (rightPadle.rightPaddle_y <= windowDimensions.Y_MAX)
        {
            if (IsKeyDown(KEY_DOWN))
            {
                rightPadle.rightPaddle_y += paddlesSpeed;
            }
        }

        // BALL LOGIC
        DrawCircle(ball.ball_x, ball.ball_y, ball.ballRadius, ball.ballColor);

        ball.ball_y += ballSpeed;

        if (ball.ball_y < windowDimensions.y_min || ball.ball_y > windowDimensions.Y_MAX)
        {
            ballSpeed = -ballSpeed;
        }

        EndDrawing();
    }
}