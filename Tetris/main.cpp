#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(520, 640, "TETRIS - Made by Taha Anwer(Team Lead),Syed Sultan,Hamza Atif");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/retro.ttf", 64, 0, 0);

    Game game = Game();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 20}, 34, 2, WHITE);
        DrawTextEx(font, "Next", {370, 150}, 34, 2, WHITE);
        DrawTextEx(font, "Press UP to rotate", {20, 590}, 20, 1, GRAY);

        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 34, 2, WHITE);
        }

        DrawRectangleRounded({320, 55, 170, 60}, 0.25, 6, lightBlue);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 34, 2);
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 65}, 34, 2, WHITE);

        DrawRectangleRounded({320, 200, 170, 180}, 0.25, 6, cyan);

        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
