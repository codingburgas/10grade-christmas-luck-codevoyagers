#include "raylib.h"
#include "philosopher.h"

void DrawPhilosopherComparison() {
    DrawText("Philosopher 1 vs Philosopher 2", 200, 100, 20, BLACK);
    DrawText("Philosopher 1 Theory: ...", 200, 200, 20, BLACK);
    DrawText("Philosopher 2 Theory: ...", 200, 300, 20, BLACK);
    DrawText("Press BACKSPACE to go back", 200, 400, 20, BLACK);
}
