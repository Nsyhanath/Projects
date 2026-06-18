#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>
#include <stdlib.h>

#define MAXIMUMVALUE 99 //maximum number of stones per pile
#define MAXIMUMPILES 99 //maximum number of piles
#define MINIMUMVALUE 1 //minimum number of piles or stones
using namespace std;

// game info struct
struct gameInfo {
    int piles = 0; // number of piles
    int stones = 0; // number of stones
    bool computer = false; // computer

    string player1, player2; // player names
};

//function prototypes
inline void makePiles(vector<int>&, gameInfo&);
inline void printPiles(vector<int>&);
inline int readCommands(int, char**, gameInfo&);
inline void readNames(gameInfo&);
inline bool is_num(char*);
inline std::pair<int, int> computer_move(vector<int>&);
inline void game(gameInfo&);

#endif
