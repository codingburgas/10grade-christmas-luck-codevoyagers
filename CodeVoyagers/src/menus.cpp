#include "raylib.h"
#include "menus.h"

void DrawMainMenu() {
    DrawText("Philosophy Comparison Tool", 200, 200, 20, BLACK);
    DrawText("Press ENTER to Start", 200, 300, 20, BLACK);
    DrawText("Press ESC to Exit", 200, 400, 20, BLACK);
}

void DrawPhilosopherSelection() {
    DrawText("Select two philosophers:", 200, 100, 20, BLACK);
    DrawText("1. Philosopher 1", 200, 200, 20, BLACK);
    DrawText("2. Philosopher 2", 200, 250, 20, BLACK);
    DrawText("3. Philosopher 3", 200, 300, 20, BLACK);
    DrawText("4. Philosopher 4", 200, 350, 20, BLACK);
    DrawText("5. Philosopher 5", 200, 400, 20, BLACK);
    DrawText("6. Philosopher 6", 200, 450, 20, BLACK);
    DrawText("Press BACKSPACE to go back", 200, 500, 20, BLACK);
}
