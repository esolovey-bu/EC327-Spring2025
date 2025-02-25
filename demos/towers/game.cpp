#include <stdio.h>
#include "game.h"

// basic disk transfer functions
void addToPeg(Peg* peg, int disk) {
    peg->disks[peg->currentSize] = disk;
    peg->currentSize++;
}

int removeFromPeg(Peg* peg) {
    int topOfPeg = peg->disks[peg->currentSize -1];
    peg->disks[peg->currentSize -1] = 0;
    peg->currentSize--;
    return topOfPeg;
}

void transferSingleDisk(Peg* from, Peg* to) {
    int disk = removeFromPeg(from);
    addToPeg(to, disk);
}

// debug/display functions
void printPeg(Peg* peg) {
    printf("Peg %c: ", peg->label);
    for (int j =( peg->currentSize - 1); j >=  0; j--) {
        printf("%d -> ", peg->disks[j]);
    }
    printf("\n");
}

void printState(TowersOfHanoi* game) {
    printf("\nState of Pegs:\n");
    printPeg(game->pegA);
    printPeg(game->pegB);
    printPeg(game->pegC);
    printf("\n");
}

void printMoveMessage(int numberOfDisksToMove, Peg* from, Peg* to, Peg* aux, int recursionLevel) {
    for (int format = 0; format < recursionLevel; format++) {
        for (int extraSpaces =0; extraSpaces < 4; extraSpaces++) {
            printf(" ");
        }
    }
    printf("Move %d disks from %c to %c using %c as aux\n", numberOfDisksToMove, from->label, to->label, aux->label);
}

// solving the game
void moveDisks(int numberOfDisksToMove, Peg* from, Peg* to, Peg* aux, int recursionLevel) {
    printMoveMessage(numberOfDisksToMove, from, to, aux, recursionLevel);

    if (numberOfDisksToMove == 1) {
        transferSingleDisk(from, to);
        return;
    }

    recursionLevel++;
    // step-1 : move n-1 disks out of the way
    moveDisks(numberOfDisksToMove - 1, from, aux, to, recursionLevel);

    // step-2 : move single, biggest disk to destination
    moveDisks(1, from, to, aux, recursionLevel);

    // step-3 : put everything that we moved out of the way onto destination
    moveDisks(numberOfDisksToMove - 1, aux, to, from, recursionLevel);
}