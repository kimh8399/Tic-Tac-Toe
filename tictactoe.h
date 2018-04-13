#ifndef TICTACTOE_H_INCLUDED
#define TICTACTOE_H_INCLUDED

#include "libraries.h"


class Tictactoe
{
public:
    Tictactoe(void);
    void play(const unsigned state, const bool save);
    void outputBoard(void);
private:
    void checkState(void);
    void place(const Piece piece, const unsigned column, const unsigned row);
    bool checkHor(const unsigned rowNum);
    bool checkVert(const unsigned colNum);
    bool checkDiag(const int slope);
    vector <vector<Piece>> t_board;
    bool gameOver;
    Piece t_winner;
};

#endif // TICTACTOE_H_INCLUDED
