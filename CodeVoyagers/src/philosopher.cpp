#include "philosopher.h"
#include <string> // Correctly include string header

const char* philosopherNames[] = {
    "Aristotle",
    "Socrates",
    "Plato",
    "Sigmund Freud",
    "Karl Marx",
    "Immanuel Kant"
};

const char* philosopherTheories[] = {
    "Aristotle's Theory:\nVirtue ethics focuses on the development of virtuous character traits.\nHe believed that moral virtue is achieved through habitual practice.\nAccording to Aristotle, living a virtuous life leads to true happiness.",
    "Socrates' Theory:\nSocratic method involves asking a series of questions\nto stimulate critical thinking and illuminate ideas.\nSocrates believed in seeking knowledge through dialogue and self-examination.",
    "Plato's Theory:\nTheory of Forms posits that non-material abstract forms\nor ideas are the highest and most fundamental kind of reality.\nPlato believed that the material world is a shadow of the true reality of the Forms.",
    "Sigmund Freud's Theory:\nPsychoanalysis explores the influence of the unconscious mind\non behavior. He proposed that unresolved conflicts from childhood\nimpact adult personality and behavior.",
    "Karl Marx's Theory:\nMarxism critiques capitalism and advocates for a classless society.\nHe believed that history is driven by class struggles\nand that the working class should overthrow the ruling class.",
    "Immanuel Kant's Theory:\nCategorical Imperative is a moral law that is universally binding.\nKant argued that one should act only according to maxims that can be\nuniversally applied, emphasizing duty and moral principles."
};

Texture2D philosopherImages[6];

void LoadPhilosopherImages() {
    philosopherImages[0] = LoadTexture("./assets/aristotle.png");
    philosopherImages[1] = LoadTexture("./assets/plato.png");
    philosopherImages[2] = LoadTexture("./assets/socrates.png");
    philosopherImages[3] = LoadTexture("./assets/sigmund_freud.png");
    philosopherImages[4] = LoadTexture("./assets/karl_marx.png");
    philosopherImages[5] = LoadTexture("./assets/kant.png");
}

void UnloadPhilosopherImages() {
    for (int i = 0; i < 6; i++) {
        UnloadTexture(philosopherImages[i]);
    }
}

void DrawPhilosopherComparison(int philosopher1, int philosopher2) {
    DrawText(TextFormat("%s vs %s", philosopherNames[philosopher1], philosopherNames[philosopher2]), 400, 500, 20, BLACK);
    DrawTexture(philosopherImages[philosopher1], 200, 150, WHITE);
    DrawText(philosopherTheories[philosopher1], 200, 600, 20, BLACK);
    DrawTexture(philosopherImages[philosopher2], 600, 150, WHITE);
    DrawText(philosopherTheories[philosopher2], 600, 600, 20, BLACK);
    DrawText("Press BACKSPACE to go back", 200, 600, 20, BLACK);
}

void DrawPhilosopherCards(int* selectedPhilosopher, int chosenPhilosopher) {
    for (int i = 0; i < 6; i++) {
        if (i == chosenPhilosopher) continue; // Skip the already chosen philosopher

        int row = i / 3;
        int col = i % 3;

        // Define card position and size
        Rectangle card = { 300 * col + 50, 300 * row + 100, 200, 250 };
        DrawRectangle(card.x, card.y, card.width, card.height, LIGHTGRAY);

        // Define source and destination rectangles for the image
        Rectangle source = { 0.0f, 0.0f, (float)philosopherImages[i].width, (float)philosopherImages[i].height };
        Rectangle dest = { card.x + 25, card.y + 25, 150, 150 }; // Adjust the size and position of the image

        // Draw the image within the card
        DrawTexturePro(philosopherImages[i], source, dest, (Vector2) ( 0, 0 ), 0.0f, WHITE);

        // Display the philosopher's name on two lines if it's too long
        const char* name = philosopherNames[i];
        int nameLength = MeasureText(name, 20);
        if (nameLength > 160) {
            int splitIndex = nameLength / 2;
            int splitPoint = splitIndex;
            while (name[splitPoint] != ' ' && splitPoint < nameLength) splitPoint++;
            if (splitPoint == nameLength) splitPoint = splitIndex;
            char nameLine1[21] = { 0 };
            char nameLine2[21] = { 0 };
            strncpy(nameLine1, name, splitPoint);
            strncpy(nameLine2, name + splitPoint + 1, nameLength - splitPoint - 1);

            DrawText(nameLine1, card.x + 10, card.y + 200, 20, BLACK); // Adjust the text position
            DrawText(nameLine2, card.x + 10, card.y + 220, 20, BLACK); // Adjust the text position
        }
        else {
            DrawText(name, card.x + 10, card.y + 220, 20, BLACK); // Adjust the text position
        }

        // Check for card click to select philosopher
        if (CheckCollisionPointRec(GetMousePosition(), card) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            *selectedPhilosopher = i;
        }
    }
}
