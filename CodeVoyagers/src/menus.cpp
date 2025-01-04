#include "raylib.h"
#include "menus.h"

void DrawMainMenu() {
    DrawText("Philosophy Comparison Tool", 200, 200, 20, BLACK);
    DrawText("Press ENTER to Start", 200, 300, 20, BLACK);
    DrawText("Press ESC to Exit", 200, 400, 20, BLACK);
}

void DrawPhilosopherSelection(int* selectedPhilosopher1, int* selectedPhilosopher2) {
    DrawText("Select two philosophers:", 200, 100, 20, BLACK);
    DrawText("1. Aristotle", 200, 200, 20, BLACK);
    DrawText("2. Socrates", 200, 250, 20, BLACK);
    DrawText("3. Plato", 200, 300, 20, BLACK);
    DrawText("4. Sigmund Freud", 200, 350, 20, BLACK);
    DrawText("5. Karl Marx", 200, 400, 20, BLACK);
    DrawText("6. Immanuel Kant", 200, 450, 20, BLACK);
    DrawText("Press BACKSPACE to go back", 200, 500, 20, BLACK);

    if (IsKeyPressed(KEY_ONE)) {
        if (*selectedPhilosopher1 == -1) *selectedPhilosopher1 = 0;
        else if (*selectedPhilosopher2 == -1) *selectedPhilosopher2 = 0;
    }
    else if (IsKeyPressed(KEY_TWO)) {
        if (*selectedPhilosopher1 == -1) *selectedPhilosopher1 = 1;
        else if (*selectedPhilosopher2 == -1) *selectedPhilosopher2 = 1;
    }
    else if (IsKeyPressed(KEY_THREE)) {
        if (*selectedPhilosopher1 == -1) *selectedPhilosopher1 = 2;
        else if (*selectedPhilosopher2 == -1) *selectedPhilosopher2 = 2;
    }
    else if (IsKeyPressed(KEY_FOUR)) {
        if (*selectedPhilosopher1 == -1) *selectedPhilosopher1 = 3;
        else if (*selectedPhilosopher2 == -1) *selectedPhilosopher2 = 3;
    }
    else if (IsKeyPressed(KEY_FIVE)) {
        if (*selectedPhilosopher1 == -1) *selectedPhilosopher1 = 4;
        else if (*selectedPhilosopher2 == -1) *selectedPhilosopher2 = 4;
    }
    else if (IsKeyPressed(KEY_SIX)) {
        if (*selectedPhilosopher1 == -1) *selectedPhilosopher1 = 5;
        else if (*selectedPhilosopher2 == -1) *selectedPhilosopher2 = 5;
    }
}
