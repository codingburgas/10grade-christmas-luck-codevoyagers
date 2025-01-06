#include "raylib.h"
#include "menus.h"
#include "philosopher.h"

int selectedPhilosopher1 = -1;
int selectedPhilosopher2 = -1;
int currentScreen = 0;
int selectionPhase = 1;
Texture2D background; // Add a global background texture

int main() {
    InitWindow(1600, 900, "Philosophy Comparison Tool");

    // Load and set the window icon
    Image logo = LoadImage("../assets/logo.png"); // Load the logo image
    SetWindowIcon(logo); // Set the window icon
    UnloadImage(logo); // Unload the image after setting it as the icon

    SetTargetFPS(60);

    // Load philosopher images
    LoadPhilosopherImages();
    background = LoadTexture("./assets/backgroundImage.png"); // Load the background image

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw background image
        DrawTexture(background, 0, 0, WHITE);

        if (currentScreen == 0) {
            DrawMainMenu();
            if (IsKeyPressed(KEY_ENTER)) currentScreen = 1;
            if (IsKeyPressed(KEY_ESCAPE)) break;
        }
        else if (currentScreen == 1) {
            DrawPhilosopherSelection(&selectedPhilosopher1, &selectedPhilosopher2, selectionPhase);
            if (IsKeyPressed(KEY_BACKSPACE)) currentScreen = 0;

            // Update selection phase
            if (selectionPhase == 1 && selectedPhilosopher1 != -1) {
                selectionPhase = 2;
            }
            else if (selectionPhase == 2 && selectedPhilosopher2 != -1) {
                currentScreen = 2;
            }
        }
        else if (currentScreen == 2) {
            DrawPhilosopherComparison(selectedPhilosopher1, selectedPhilosopher2);
            if (IsKeyPressed(KEY_BACKSPACE)) {
                currentScreen = 1;
                selectionPhase = 1;
                selectedPhilosopher1 = -1;
                selectedPhilosopher2 = -1;
            }
        }

        EndDrawing();
    }

    // Unload philosopher images and background
    UnloadPhilosopherImages();
    UnloadTexture(background);

    CloseWindow();

    return 0;
}
