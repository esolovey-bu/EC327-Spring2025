#ifndef PEG_H
#define PEG_H

#define DISKS 3

struct Peg {
    char label;
    int disks[DISKS];
    int currentSize = 0;
};

struct TowersOfHanoi {
    Peg* pegA;
    Peg* pegB;
    Peg* pegC;
};

// basic disk transfer functions
void addToPeg(Peg* peg, int disk);
int removeFromPeg(Peg* peg);
void transferSingleDisk(Peg* from, Peg* to);

// debug/display functions
void printPeg(Peg* peg);
void printState(TowersOfHanoi* game);
void printMoveMessage(int numberOfDisksToMove, Peg* from, Peg* to, Peg* aux, int recursionLevel);

// solving the game
void moveDisks(int numberOfDisksToMove, Peg* from, Peg* to, Peg* aux, int recursionLevel);

#endif //PEG_H
