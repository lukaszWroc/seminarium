#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
protected:
    int possitionOnBoard[12];
    int possibleMoves[12];
    int defaultMoves[12];
    int possibleMovesCounter[12];
    int possibleAttack[12];
    int possibleAttackCounter[12];
    int board[8][8];
    int endRegion;
    int allAttacks;
    int allMoves;
    int attackIdx;
    bool endattack;

    int randomMove(int from, int to);
    std::pair<int,int> MoveFromTo(int x1, int y1, int x2, int y2);
    void changePossibleMoves(int idx, int x, int y);
    void setAttackParameters(int x, int y);

    std::pair<int,int> makeMove(int idx, int cnt);
    std::pair<int,int> makeAttack(int idx, int cnt);

    void crossCheck1(int x, int y);
    void crossCheck2(int x, int y);
    void changePossibleMoves2(int x1, int y1, int x2, int y2, bool state);
    void changePossibleMoves1(int x1, int y1, int x2, int y2, bool state);

    bool validate(int x, int y);
    int getX(int x);
    int getY(int y);

public: 
    Player();
    void printMoves(int* tab, int* tabCnt, int d, int s, int e);
    void displayPossibleMoves();
    std::pair<int,int> move();
    std::pair<int,int> attackAgain();
    inline bool isAbleToMove(){return allMoves;}
    inline bool needToAttack()
    {
        if(attackIdx != -1)
            return true;
        
        if(endattack)
        {
            endattack=false;
            return false;
        }

        return allAttacks;
    };
    void update(int from, int to);
};

#endif // PLAYER_H