// MyPong Game - 04/02/2023

// By Pecas_Dev

#include "raylib.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

struct LeftPaddle
{
    float leftPaddle_x{10};
    float leftPaddle_y{350};
    float leftPaddle_width{25};
    float leftPaddle_height{125};
    Color leftPaddleColor{WHITE};

    Rectangle leftPaddleRec;

    // Left Paddle Edges
    float LeftPoint_X{leftPaddle_x};
    float RightPoint_X{leftPaddle_x + leftPaddle_width};
    float UpperPoint_Y{leftPaddle_y};
    float BottomPoint_Y{leftPaddle_y + leftPaddle_height};

    // WindowColliders
    int x_min{10};
    int X_MAX{965};

    int y_min{10};
    int Y_MAX{665};
};

struct RightPaddle
{
    float rightPaddle_x{965};
    float rightPaddle_y{350};
    float rightPaddle_width{25};
    float rightPaddle_height{125};
    Color rightPaddleColor{WHITE};

    Rectangle rightPaddleRec;

    // Right Paddle Edges
    float LeftPoint_X{rightPaddle_x};
    float RightPoint_X{rightPaddle_x + rightPaddle_width};
    float UpperPoint_Y{rightPaddle_y};
    float BottomPoint_Y{rightPaddle_y + rightPaddle_height};

    // WindowColliders
    int x_min{10};
    int X_MAX{965};

    int y_min{10};
    int Y_MAX{665};
};

struct WindowDimensions
{
    const int width{1000};
    const int height{800};
};

struct Ball
{
    float ball_x{495};
    float ball_y{400};
    float ballRadius{32};
    Color ballColor{WHITE};

    float ballOriginalPosX{495};
    float ballOriginalPosY{400};

    // Ball Edges
    float Left_Circle_X{ball_x - ballRadius};
    float Right_Circle_X{ball_x + ballRadius};
    float Upper_Circle_Y{ball_y + ballRadius};
    float Bottom_Circle_Y{ball_y - ballRadius};

    // WindowColliders
    int x_min{25};
    int X_MAX{970};

    int y_min{30};
    int Y_MAX{770};

    // Point Colliders
    int x_min_Point{30};
    int X_MAX_Point{950};
};

int main()
{
    // STRUCTS VARIABLES
    LeftPaddle leftPaddle;
    RightPaddle rightPaddle;
    Ball ball;
    WindowDimensions windowDimensions;

    // PADDLES SPEED VARAIABLE DECLARATION
    float paddlesSpeed = 10;

    // BALL VARIABLES DECLARATION
    float ballSpeed = 5;
    float ballDirectionX = 1;
    float ballDirectionY = 1;
    bool ballMoving = false;

    mt19937 generator(time(0));
    uniform_real_distribution<float> distribution(-1.0, 1.0);

    int scoreLeft = 0;
    int scoreRight = 0;

    int Fps{60};

    InitWindow(windowDimensions.width, windowDimensions.height, "MyPong");

    SetTargetFPS(Fps);

    while (!WindowShouldClose())
    {
        // GAME LOGIC STARTS
        BeginDrawing();
        ClearBackground(BLACK);

        // Middle line & Score
        DrawRectangle(494, 0, 6, 850, WHITE);
        DrawText(TextFormat("%d", scoreLeft), 850, 50, 100, RED);
        DrawText(TextFormat("%d", scoreRight), 100, 50, 100, RED);

        //----------------------------------------------------------------------------------------------------------------------------------------------------------------
        // LEFT PADDLE
        DrawRectangle(leftPaddle.leftPaddle_x, leftPaddle.leftPaddle_y, leftPaddle.leftPaddle_width, leftPaddle.leftPaddle_height, leftPaddle.leftPaddleColor);

        // LEFT PADDLE MOVEMENT
        if (leftPaddle.leftPaddle_y >= leftPaddle.y_min)
        {
            if (IsKeyDown(KEY_W))
            {
                leftPaddle.leftPaddle_y -= paddlesSpeed;
            }
        }

        if (leftPaddle.leftPaddle_y <= leftPaddle.Y_MAX)
        {
            if (IsKeyDown(KEY_S))
            {
                leftPaddle.leftPaddle_y += paddlesSpeed;
            }
        }

        // LEFT PADDLE COLLISION
        leftPaddle.leftPaddleRec.width = leftPaddle.leftPaddle_width;
        leftPaddle.leftPaddleRec.height = leftPaddle.leftPaddle_height;

        Rectangle LeftPaddleRec{
            leftPaddle.leftPaddle_x,
            leftPaddle.leftPaddle_y,
            leftPaddle.leftPaddleRec.width,
            leftPaddle.leftPaddleRec.height};

        // LEFT PADDLE - BALL COLLISION
        if (CheckCollisionCircleRec(Vector2{ball.ball_x, ball.ball_y}, ball.ballRadius, LeftPaddleRec))
        {
            ballDirectionX = -ballDirectionX;         //"Push" in the opposite direction - LeftPaddle
            ballDirectionY = distribution(generator); // Randomness offset in the Y axis - LeftPaddle
        }

        //----------------------------------------------------------------------------------------------------------------------------------------------------------------
        // RIGHT PADDLE
        DrawRectangle(rightPaddle.rightPaddle_x, rightPaddle.rightPaddle_y, rightPaddle.rightPaddle_width, rightPaddle.rightPaddle_height, rightPaddle.rightPaddleColor);

        // RIGHT PADDLE MOVEMENT
        if (rightPaddle.rightPaddle_y >= rightPaddle.y_min)
        {
            if (IsKeyDown(KEY_UP))
            {
                rightPaddle.rightPaddle_y -= paddlesSpeed;
            }
        }

        if (rightPaddle.rightPaddle_y <= rightPaddle.Y_MAX)
        {
            if (IsKeyDown(KEY_DOWN))
            {
                rightPaddle.rightPaddle_y += paddlesSpeed;
            }
        }

        // RIGHT PADDLE COLLISION
        rightPaddle.rightPaddleRec.width = rightPaddle.rightPaddle_width;
        rightPaddle.rightPaddleRec.height = rightPaddle.rightPaddle_height;

        Rectangle RightPaddleRec{
            rightPaddle.rightPaddle_x,
            rightPaddle.rightPaddle_y,
            rightPaddle.rightPaddleRec.width,
            rightPaddle.rightPaddleRec.height};

        // RIGHT PADDLE - BALL COLLISION
        if (CheckCollisionCircleRec(Vector2{ball.ball_x, ball.ball_y}, ball.ballRadius, RightPaddleRec))
        {
            ballDirectionX = -ballDirectionX;         //"Push" in the opposite direction - RightPaddle
            ballDirectionY = distribution(generator); // Randomness offset in the Y axis - RightPaddle
        }

        //----------------------------------------------------------------------------------------------------------------------------------------------------------------
        // BALL LOGIC
        DrawCircle(ball.ball_x, ball.ball_y, ball.ballRadius, ball.ballColor);

        // BALL SPEED - DIRECTION SETTINGS
        if (ballMoving)
        {
            ball.ball_x += ballSpeed * ballDirectionX;
            ball.ball_y += ballSpeed * ballDirectionY;
        }

        // BALL MOVEMENT
        if (ball.ball_y <= ball.y_min || ball.ball_y >= ball.Y_MAX)
        {
            ballDirectionY = -ballDirectionY;
        }

        // BALL INITIAL FORCE
        if (IsKeyPressed(KEY_SPACE) && !ballMoving)
        {
            ballDirectionX = distribution(generator) * 3; // Offset Inital force in the X-Axis
            ballDirectionY = distribution(generator) * 3; // Offset Inital force in the Y-Axis
            ballMoving = true;
        }

        // BALL RESET + LEFT PADDLE SCORE
        if (ball.ball_x <= ball.x_min_Point)
        {
            ball.ball_x = ball.ballOriginalPosX;
            ball.ball_y = ball.ballOriginalPosY;
            ballMoving = false;
            scoreLeft++;
        }

        // BALL RESET + RIGHT PADDLE SCORE
        if (ball.ball_x >= ball.X_MAX_Point)
        {
            ball.ball_x = ball.ballOriginalPosX;
            ball.ball_y = ball.ballOriginalPosY;
            ballMoving = false;
            scoreRight++;
        }

        //----------------------------------------------------------------------------------------------------------------------------------------------------------------
        // GAME LOGIC ENDS
        EndDrawing();
    }

    CloseWindow();

    return 0;
}