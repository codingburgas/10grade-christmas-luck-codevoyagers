#include "raylib.h"
#include "menus.h"
#include"philosopher.h"

void DrawMainMenu() {
    DrawText("Welcome to the Philosophy Comparison Tool", 400, 200, 30, BLACK);
    DrawText("Press ENTER to start", 600, 400, 20, BLACK);
}

void DrawPhilosopherSelection(int* selectedPhilosopher1, int* selectedPhilosopher2, int selectionPhase) {
    DrawText("Select Philosophers to Compare", 100, 50, 30, BLACK);

    if (selectionPhase == 1) {
        DrawText("Select the first philosopher", 100, 100, 20, BLACK);
        DrawPhilosopherCards(selectedPhilosopher1, -1);
    }
    else if (selectionPhase == 2) {
        DrawText("Select the second philosopher", 100, 100, 20, BLACK);
        DrawPhilosopherCards(selectedPhilosopher2, *selectedPhilosopher1);
    }
}
