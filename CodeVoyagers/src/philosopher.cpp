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
    "Aristotle's Theory:\nVirtue ethics focuses on the \ndevelopment of virtuous character traits.\nHe believed that moral virtue is \nachieved through habitual practice.\nAccording to Aristotle, living a virtuous \nlife leads to true happiness.",
    "Socrates' Theory:\nSocratic method involves asking a series\nof questions to stimulate critical \nthinking and illuminate ideas.\nSocrates believed in seeking knowledge \nthrough dialogue and self-examination.",
    "Plato's Theory:\nTheory of Forms posits that non-material \nabstract forms or ideas are the highest \nand most fundamental kind of reality.\nPlato believed that the material \nworld is a shadow of the true reality of the Forms.",
    "Sigmund Freud's Theory:\nPsychoanalysis explores the \ninfluence of the unconscious mind on behavior. \nHe proposed that unresolved \nconflicts from childhood impact \nadult personality and behavior.",
    "Karl Marx's Theory:\nMarxism critiques capitalism and \nadvocates for a classless society. He believed \nthat history is driven by class struggles\nand that the working class should \noverthrow the ruling class.",
    "Immanuel Kant's Theory:\nCategorical Imperative is a moral law \nthat is universally binding. Kant argued \nthat one should act only according to maxims \nthat can be universally applied, \nemphasizing duty and moral principles."
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
    const char* comparisonText = TextFormat("%s vs %s", philosopherNames[philosopher1], philosopherNames[philosopher2]);
    int comparisonTextWidth = MeasureText(comparisonText, 20);

    // Draw background rectangle for comparison text
    DrawRectangle(680 - 10, 390 - 10, comparisonTextWidth + 20, 40, LIGHTGRAY);

    // Draw comparison text
    DrawText(comparisonText, 680, 390, 20, BLACK);

    DrawTexture(philosopherImages[philosopher1], 200, 150, WHITE);

    // Draw background rectangle for philosopher 1's theory
    int text1Width = MeasureText(philosopherTheories[philosopher1], 20);
    DrawRectangle(200 - 10, 520 - 10, text1Width + 20, 5 * 36 + 36, LIGHTGRAY); // Adjusted for 5 lines

    // Draw philosopher 1's theory
    DrawText(philosopherTheories[philosopher1], 200, 520, 20, BLACK);

    DrawTexture(philosopherImages[philosopher2], 1000, 150, WHITE);

    // Draw background rectangle for philosopher 2's theory
    int text2Width = MeasureText(philosopherTheories[philosopher2], 20);
    DrawRectangle(1000 - 10, 520 - 10, text2Width + 20, 5 * 32 + 32, LIGHTGRAY); // Adjusted for 5 lines

    // Draw philosopher 2's theory
    DrawText(philosopherTheories[philosopher2], 1000, 520, 20, BLACK);

    // Draw background rectangle for "Press BACKSPACE to go back"
    const char* backText = "Press BACKSPACE to go back";
    int backTextWidth = MeasureText(backText, 20);
    DrawRectangle(680 - 10, 810 - 10, backTextWidth + 20, 40, LIGHTGRAY);

    // Draw "Press BACKSPACE to go back" text
    DrawText(backText, 680, 815, 20, BLACK);
}

void DrawPhilosopherCards(int* selectedPhilosopher, int chosenPhilosopher) {
    int screenWidth = 1600;
    int screenHeight = 900;
    int cardWidth = 200;
    int cardHeight = 250;
    int cardsPerRow = 3;
    int numCards = 6;

    int horizontalSpacing = (screenWidth - (cardWidth * cardsPerRow)) / (cardsPerRow + 1);
    int verticalSpacing = (screenHeight - (cardHeight * (numCards / cardsPerRow))) / (numCards / cardsPerRow + 1);

    for (int i = 0; i < numCards; i++) {
        if (i == chosenPhilosopher) continue; // Skip the already chosen philosopher

        int row = i / cardsPerRow;
        int col = i % cardsPerRow;

        // Define card position and size
        Rectangle card = {
            horizontalSpacing * (col + 1) + cardWidth * col,
            verticalSpacing * (row + 1) + cardHeight * row,
            cardWidth,
            cardHeight
        };
        DrawRectangle(card.x, card.y, card.width, card.height, LIGHTGRAY);

        // Define source and destination rectangles for the image
        Rectangle source = { 0.0f, 0.0f, (float)philosopherImages[i].width, (float)philosopherImages[i].height };
        Rectangle dest = { card.x + 25, card.y + 25, 150, 150 }; // Adjust the size and position of the image

        // Draw the image within the card
        DrawTexturePro(philosopherImages[i], source, dest, (Vector2)(0, 0), 0.0f, WHITE);

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
