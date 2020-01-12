#include "whiteplayer.h"

WhitePlayer::WhitePlayer()
{
    endRegion = 7;
    
    possibleMoves[0] = 0b1001;
    possibleMoves[1] = 0b1001;
    possibleMoves[2] = 0b1001;
    possibleMoves[3] = 0b1000;
    possibleMovesCounter[0] = 2;
    possibleMovesCounter[1] = 2;
    possibleMovesCounter[2] = 2;
    possibleMovesCounter[3] = 1;

    possitionOnBoard[0] = 1 + 8*2;
    possitionOnBoard[1] = 3 + 8*2;
    possitionOnBoard[2] = 5 + 8*2;
    possitionOnBoard[3] = 7 + 8*2;
    possitionOnBoard[4] = 0 + 8*1;
    possitionOnBoard[5] = 2 + 8*1;
    possitionOnBoard[6] = 4 + 8*1;
    possitionOnBoard[7] = 6 + 8*1;
    possitionOnBoard[8] = 1 + 8*0;
    possitionOnBoard[9] = 3 + 8*0;
    possitionOnBoard[10] = 5 + 8*0;
    possitionOnBoard[11] = 7 + 8*0;

    defaultMoves[0] = 0b1001;
    defaultMoves[1] = 0b1001;
    defaultMoves[2] = 0b1001;
    defaultMoves[3] = 0b1001;
    defaultMoves[4] = 0b1001;
    defaultMoves[5] = 0b1001;
    defaultMoves[6] = 0b1001;
    defaultMoves[7] = 0b1001;
    defaultMoves[8] = 0b1001;
    defaultMoves[9] = 0b1001;
    defaultMoves[10] = 0b1001;
    defaultMoves[11] = 0b1001;
    
    // -2 miejsce wolne -1 pionek przeciwnika >0 nasz pionek
    board[1][0] = 8;
    board[3][0] = 9;
    board[5][0] = 10;
    board[7][0] = 11;
    board[0][1] = 4;
    board[2][1] = 5;
    board[4][1] = 6;
    board[6][1] = 7;
    board[1][2] = 0;
    board[3][2] = 1;
    board[5][2] = 2;
    board[7][2] = 3;
    board[0][5] = -1;
    board[2][5] = -1;
    board[4][5] = -1;
    board[6][5] = -1;
    board[1][6] = -1;
    board[3][6] = -1;
    board[5][6] = -1;
    board[7][6] = -1;
    board[0][7] = -1;
    board[2][7] = -1;
    board[4][7] = -1;
    board[6][7] = -1;
}