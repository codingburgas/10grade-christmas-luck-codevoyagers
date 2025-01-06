#include "raylib.h"
#include "menus.h"
#include "philosopher.h"

void DrawMainMenu() {
    // Coordinates and dimensions for "Welcome to the Philosophy Comparison Tool"
    int text1PosX = 250;
    int text1PosY = 300;
    int text1Width = MeasureText("Welcome to the Philosophy Comparison Tool", 50);
    int text1Height = 50;

    // Coordinates and dimensions for "Press ENTER to start"
    int text2PosX = 680;
    int text2PosY = 400;
    int text2Width = MeasureText("Press ENTER to start", 20);
    int text2Height = 20;

    // Draw the background rectangle for "Welcome to the Philosophy Comparison Tool"
    DrawRectangle(text1PosX - 10, text1PosY - 10, text1Width + 20, text1Height + 20, LIGHTGRAY);
    DrawText("Welcome to the Philosophy Comparison Tool", text1PosX, text1PosY, 50, BLACK);

    // Draw the background rectangle for "Press ENTER to start"
    DrawRectangle(text2PosX - 10, text2PosY - 10, text2Width + 20, text2Height + 20, LIGHTGRAY);
    DrawText("Press ENTER to start", text2PosX, text2PosY, 20, BLACK);
}

void DrawPhilosopherSelection(int* selectedPhilosopher1, int* selectedPhilosopher2, int selectionPhase) {
    // Coordinates and dimensions for "Select Philosophers to Compare"
    int text3PosX = 100;
    int text3PosY = 50;
    int text3Width = MeasureText("Select Philosophers to Compare", 30);
    int text3Height = 30;

    // Draw the background rectangle for "Select Philosophers to Compare"
    DrawRectangle(text3PosX - 10, text3PosY - 10, text3Width + 20, text3Height + 20, LIGHTGRAY);
    DrawText("Select Philosophers to Compare", text3PosX, text3PosY, 30, BLACK);

    if (selectionPhase == 1) {
        // Coordinates and dimensions for "Select the first philosopher"
        int text4PosX = 100;
        int text4PosY = 100;
        int text4Width = MeasureText("Select the first philosopher", 20);
        int text4Height = 20;

        // Draw the background rectangle for "Select the first philosopher"
        DrawRectangle(text4PosX - 10, text4PosY - 10, text4Width + 20, text4Height + 20, LIGHTGRAY);
        DrawText("Select the first philosopher", text4PosX, text4PosY, 20, BLACK);

        DrawPhilosopherCards(selectedPhilosopher1, -1);
    }
    else if (selectionPhase == 2) {
        // Coordinates and dimensions for "Select the second philosopher"
        int text5PosX = 100;
        int text5PosY = 100;
        int text5Width = MeasureText("Select the second philosopher", 20);
        int text5Height = 20;

        // Draw the background rectangle for "Select the second philosopher"
        DrawRectangle(text5PosX - 10, text5PosY - 10, text5Width + 20, text5Height + 20, LIGHTGRAY);
        DrawText("Select the second philosopher", text5PosX, text5PosY, 20, BLACK);

        DrawPhilosopherCards(selectedPhilosopher2, *selectedPhilosopher1);
    }
}
