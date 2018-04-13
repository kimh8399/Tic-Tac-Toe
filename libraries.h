#ifndef LIBRARIES_H_INCLUDED
#define LIBRARIES_H_INCLUDED

#define RANDOM 0
#define NET 1
#define BOARD_SIZE 3

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

typedef  vector<int> Layer;

enum Piece:int{Empty = 0, Nought = 1, Cross = 2};

#endif // LIBRARIES_H_INCLUDED
