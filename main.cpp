#include "libraries.h"
#include "tictactoe.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Tictactoe myBoard;
    myBoard.play(RANDOM, false);
    myBoard.outputBoard();

}
