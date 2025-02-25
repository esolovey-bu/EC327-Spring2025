#include "game.h"

int main() {
    Peg pegA = {'A'};
    Peg pegB = {'B'};
    Peg pegC = {'C'};

    for (int i = DISKS; i > 0; i--) {
        addToPeg(&pegA, i);
    }

    TowersOfHanoi game = {&pegA, &pegB, &pegC};

    printState(&game);

    moveDisks(DISKS, game.pegA, game.pegB, game.pegC, 0);
    printState(&game);

    return 0;
}