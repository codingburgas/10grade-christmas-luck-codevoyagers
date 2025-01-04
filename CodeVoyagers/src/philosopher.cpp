#include "raylib.h"
#include "philosopher.h"

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

void DrawPhilosopherComparison(int philosopher1, int philosopher2) {
    DrawText(TextFormat("%s vs %s", philosopherNames[philosopher1], philosopherNames[philosopher2]), 200, 100, 20, BLACK);
    DrawText(philosopherTheories[philosopher1], 200, 200, 20, BLACK);
    DrawText(philosopherTheories[philosopher2], 200, 300, 20, BLACK);
    DrawText("Press BACKSPACE to go back", 200, 400, 20, BLACK);
}
