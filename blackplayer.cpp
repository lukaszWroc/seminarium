#include "blackplayer.h"

BlackPlayer::BlackPlayer()
{
    endRegion = 0;

    possibleMoves[8] = 0b0010;
    possibleMoves[9] = 0b0110;
    possibleMoves[10] = 0b0110;
    possibleMoves[11] = 0b0110;
    possibleMovesCounter[8] = 1;
    possibleMovesCounter[9] = 2;
    possibleMovesCounter[10] = 2;
    possibleMovesCounter[11] = 2;

    possitionOnBoard[0] = 0 + 8*7;
    possitionOnBoard[1] = 2 + 8*7;
    possitionOnBoard[2] = 4 + 8*7;
    possitionOnBoard[3] = 6 + 8*7;
    possitionOnBoard[4] = 1 + 8*6;
    possitionOnBoard[5] = 3 + 8*6;
    possitionOnBoard[6] = 5 + 8*6;
    possitionOnBoard[7] = 7 + 8*6;
    possitionOnBoard[8] = 0 + 8*5;
    possitionOnBoard[9] = 2 + 8*5;
    possitionOnBoard[10] = 4 + 8*5;
    possitionOnBoard[11] = 6 + 8*5;

    defaultMoves[0]  = 0b0110;
    defaultMoves[1]  = 0b0110;
    defaultMoves[2]  = 0b0110;
    defaultMoves[3]  = 0b0110;
    defaultMoves[4]  = 0b0110;
    defaultMoves[5]  = 0b0110;
    defaultMoves[6]  = 0b0110;
    defaultMoves[7]  = 0b0110;
    defaultMoves[8]  = 0b0110;
    defaultMoves[9]  = 0b0110;
    defaultMoves[10]  = 0b0110;
    defaultMoves[11]  = 0b0110;
    
    // -2 miejsce wolne -1 pionek przeciwnika >0 nasz pionek
    board[1][0] = -1;
    board[3][0] = -1;
    board[5][0] = -1;
    board[7][0] = -1;
    board[0][1] = -1;
    board[2][1] = -1;
    board[4][1] = -1;
    board[6][1] = -1;
    board[1][2] = -1;
    board[3][2] = -1;
    board[5][2] = -1;
    board[7][2] = -1;
    board[0][5] = 8;
    board[2][5] = 9;
    board[4][5] = 10;
    board[6][5] = 11;
    board[1][6] = 4;
    board[3][6] = 5;
    board[5][6] = 6;
    board[7][6] = 7;
    board[0][7] = 0;
    board[2][7] = 1;
    board[4][7] = 2;
    board[6][7] = 3;
}