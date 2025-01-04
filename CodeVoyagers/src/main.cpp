#include "raylib.h"
#include "menus.h"
#include "philosopher.h"

int selectedPhilosopher1 = -1;
int selectedPhilosopher2 = -1;

int main() {
    InitWindow(1280, 720, "Philosophy Comparison Tool");

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
            DrawPhilosopherSelection(&selectedPhilosopher1, &selectedPhilosopher2);
            if (IsKeyPressed(KEY_BACKSPACE)) currentScreen = 0;
            if (selectedPhilosopher1 != -1 && selectedPhilosopher2 != -1) currentScreen = 2;
        }
        else if (currentScreen == 2) {
            DrawPhilosopherComparison(selectedPhilosopher1, selectedPhilosopher2);
            if (IsKeyPressed(KEY_BACKSPACE)) {
                currentScreen = 1;
                selectedPhilosopher1 = -1;
                selectedPhilosopher2 = -1;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
