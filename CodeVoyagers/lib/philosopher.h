#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include "raylib.h"

extern const char* philosopherNames[];
extern const char* philosopherTheories[];
extern Texture2D philosopherImages[6];

void LoadPhilosopherImages();
void UnloadPhilosopherImages();
void DrawPhilosopherComparison(int philosopher1, int philosopher2);
void DrawPhilosopherCards(int* selectedPhilosopher, int chosenPhilosopher);

#endif // PHILOSOPHER_H
