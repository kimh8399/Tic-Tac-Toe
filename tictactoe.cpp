#include "tictactoe.h"

Tictactoe::Tictactoe(void)
{
    gameOver = false;
    t_winner = Piece::Empty;
    vector<Piece> buffer;
    for(unsigned c = 0; c < BOARD_SIZE; c++)
    {
        buffer.push_back(Empty);
    }
    for(unsigned r = 0; r < BOARD_SIZE; r++)
    {
        t_board.push_back(buffer);
    }

    /******************* Testing **********************

    place(Piece::Cross, 0 , 2);
    place(Piece::Cross, 1 , 1);
    place(Piece::Cross, 2 , 0);
    checkState();
    cout<<t_winner;
    **/

}

void Tictactoe::play(const unsigned state, const bool save)
{
    Piece currentPiece = Piece::Cross;
    int moves = 0;
    if(state == RANDOM)
    {
        int row, column;
        bool legal = false;
        while(!gameOver)
        {
            while(!legal)
            {
                row = rand() % BOARD_SIZE;
                column = rand() % BOARD_SIZE;
                if(t_board[row][column] == Empty)
                    legal = true;
                else if(moves == BOARD_SIZE*BOARD_SIZE)
                    return;

            }
            Tictactoe::place(currentPiece, column, row);
            moves++;
            checkState();
            currentPiece = (currentPiece == Piece::Cross) ? Piece::Nought : Piece::Cross;
            legal = false;
        }
    }
}

void Tictactoe::checkState(void)
{
    vector <Piece> vertCheck(BOARD_SIZE);
    vector <Piece> horCheck(BOARD_SIZE);

    if(t_board[0][0]!= Piece::Empty)
    {
        if(checkDiag(-1))
        {
            gameOver = true;
            t_winner = t_board[0][0];
            return;
        }
    }
    else if(t_board[0][BOARD_SIZE - 1] != Piece::Empty)
    {
        if(checkDiag(+1))
        {
            gameOver = true;
            t_winner = t_board[0][BOARD_SIZE - 1];
            return;
        }
    }
    for(int increment = 0; increment < BOARD_SIZE; increment++)
    {
        if(t_board[0][increment] != Piece::Empty)
        {
            if(checkVert(increment))
            {
                gameOver = true;
                t_winner = t_board[0][increment];
                return;
            }
        }
        if(t_board[increment][0] != Piece::Empty)
        {
            if(checkHor(increment))
            {
                gameOver = true;
                t_winner = t_board[increment][0];
                return;
            }
        }
    }
}

bool Tictactoe::checkHor(const unsigned rowNum)
{
    vector<Piece> &currLayer = t_board[rowNum];
    Piece checkPiece = currLayer[0];
    for(unsigned col = 1; col < BOARD_SIZE; col++)
    {
        if(currLayer[col] != checkPiece)
            return false;
    }
    return true;
}

bool Tictactoe::checkVert(const unsigned colNum)
{
    Piece checkPiece = t_board[0][colNum];
    for(unsigned row = 1; row < BOARD_SIZE; row++)
    {
        if(t_board[row][colNum] != checkPiece)
            return false;
    }
    return true;
}

bool Tictactoe::checkDiag(const int slope)
{
    Piece checkPiece;
    int row = 1;
    if(slope < 0)
    {
        checkPiece = t_board[0][0];
        for(int col = 1; col < BOARD_SIZE; col++)
        {
            if(t_board[row][col]!=checkPiece)
                return false;
            row++;
        }
    }
    else if(slope > 0)
    {
        checkPiece = t_board[0][BOARD_SIZE - 1];
        for(int col = BOARD_SIZE - 2; col >= 0; col--)
        {
            if(t_board[row][col]!=checkPiece)
                return false;
            row++;
        }
    }
    return true;
}

void Tictactoe::place(const Piece piece, const unsigned column, const unsigned row)
{
    t_board[row][column] = piece;
}

void Tictactoe::outputBoard(void)
{
    for(unsigned r = 0; r < BOARD_SIZE; r++)
    {
        for(unsigned c = 0; c <BOARD_SIZE; c++)
        {
            if(t_board[r][c] == Piece::Cross)
                cout<<"X";
            else if(t_board[r][c] == Piece::Nought)
                cout<<"O";
            else
                cout<<"-";
        }
        cout<<endl;
    }
    if(t_winner == Piece::Cross)
        cout<<"WINNER IS CROSS"<<endl;
    else if(t_winner == Piece::Nought)
        cout<<"WINNER IS NOUGHT"<<endl;
    else
        cout<<"IT IS A TIE"<<endl;
}
