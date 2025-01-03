#include "raylib.h"
#include "menus.h"
#include "philosopher.h"

int main() {
    InitWindow(800, 600, "Philosophy Comparison Tool");

    SetTargetFPS(60);

    int currentScreen = 0;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (currentScreen == 0) {
            DrawMainMenu();
            if (IsKeyPressed(KEY_ENTER)) currentScreen = 1;
            if (IsKeyPressed(KEY_ESCAPE)) break;
        }
        else if (currentScreen == 1) {
            DrawPhilosopherSelection();
            if (IsKeyPressed(KEY_BACKSPACE)) currentScreen = 0;
            if (IsKeyPressed(KEY_ONE)) currentScreen = 2;
            if (IsKeyPressed(KEY_TWO)) currentScreen = 2;
        }
        else if (currentScreen == 2) {
            DrawPhilosopherComparison();
            if (IsKeyPressed(KEY_BACKSPACE)) currentScreen = 1;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
