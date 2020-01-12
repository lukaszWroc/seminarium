#include <random>

#include "player.h"


// --------x---y
// 0b1000 -1  +1
// 0b0100 -1  -1
// 0b0010 +1  -1
// 0b0001 +1  +1

Player::Player()
{
    for(int i=0;i<12;i++)
    {
        possibleMoves[i] = 0;
        possibleMovesCounter[i] = 0;
        possibleAttack[i] = 0;
        possibleAttackCounter[i] = 0;
    }
    
    for(int i=0;i<8;i++)
    {
        possibleMoves[i] = 0;
        possibleMovesCounter[i] = 0;
        for(int j=0;j<8;j++)
            board[i][j] = -2;
    }

    allMoves = 7;
    allAttacks = 0;
    attackIdx = -1;
    endattack = false;
}

inline int Player::getX(int x)
{
    return x&7;
}

inline int Player::getY(int y)
{
    return y>>3;
}

void Player::crossCheck1(int x, int y)
{
    if(validate(x-1, y+1) && board[x-1][y+1] >= 0)
        changePossibleMoves(board[x-1][y+1], x-1, y+1);

    if(validate(x-2, y+2) && board[x-2][y+2] >= 0)
        changePossibleMoves(board[x-2][y+2], x-2, y+2);

    if(validate(x+1, y-1) && board[x+1][y-1] >= 0)
        changePossibleMoves(board[x+1][y-1], x+1, y-1);

    if(validate(x+2, y-2) && board[x+2][y-2] >= 0)
        changePossibleMoves(board[x+2][y-2], x+2, y-2);
}

void Player::crossCheck2(int x, int y)
{
    if(validate(x-1, y-1) && board[x-1][y-1] >= 0)
        changePossibleMoves(board[x-1][y-1], x-1, y-1);

    if(validate(x-2, y-2) && board[x-2][y-2] >= 0)
        changePossibleMoves(board[x-2][y-2], x-2, y-2);

    if(validate(x+1, y+1) && board[x+1][y+1] >= 0)
        changePossibleMoves(board[x+1][y+1], x+1, y+1);

    if(validate(x+2, y+2) && board[x+2][y+2] >= 0)
        changePossibleMoves(board[x+2][y+2], x+2, y+2);
}

void Player::changePossibleMoves1(int x1, int y1, int x2, int y2, bool state)
{
    crossCheck1(x1, y1);
    crossCheck1(x2, y2);

    if(state)
    {
        if(validate(x2+1, y2+1) && board[x2+1][y2+1] >= 0)
            changePossibleMoves(board[x2+1][y2+1], x2+1, y2+1);

        if(validate(x2+2, y2+2) && board[x2+2][y2+2] >= 0)
            changePossibleMoves(board[x2+2][y2+2], x2+2, y2+2);

        if(validate(x1-1, y1-1) && board[x1-1][y1-1] >= 0)
            changePossibleMoves(board[x1-1][y1-1], x1-1, y1-1);

        if(validate(x1-2, y1-2) && board[x1-2][y1-2] >= 0)
            changePossibleMoves(board[x1-2][y1-2], x1-2, y1-2);
    }
    else
    {
        if(validate(x2-1, y2-1) && board[x2-1][y2-1] >= 0)
            changePossibleMoves(board[x2-1][y2-1], x2-1, y2-1);

        if(validate(x2-2, y2-2) && board[x2-2][y2-2] >= 0)
            changePossibleMoves(board[x2-2][y2-2], x2-2, y2-2);
        
        if(validate(x1+1, y1+1) && board[x1+1][y1+1] >= 0)
            changePossibleMoves(board[x1+1][y1+1], x1+1, y1+1);

        if(validate(x1+2, y1+2) && board[x1+2][y1+2] >= 0)
            changePossibleMoves(board[x1+2][y1+2], x1+2, y1+2);
    }
}

void Player::changePossibleMoves2(int x1, int y1, int x2, int y2, bool state)
{
    crossCheck2(x1, y1);
    crossCheck2(x2, y2);

    if(state)
    {
        if(validate(x2+1, y2-1) && board[x2+1][y2-1] >= 0)
            changePossibleMoves(board[x2+1][y2-1], x2+1, y2-1);

        if(validate(x2+2, y2-2) && board[x2+2][y2-2] >= 0)
            changePossibleMoves(board[x2+2][y2-2], x2+2, y2-2);

        if(validate(x1-1, y1+1) && board[x1-1][y1+1] >= 0)
            changePossibleMoves(board[x1-1][y1+1], x1-1, y1+1);

        if(validate(x1-2, y1+2) && board[x1-2][y1+2] >= 0)
            changePossibleMoves(board[x1-2][y1+2], x1-2, y1+2);
    }
    else
    {
        if(validate(x2-1, y2+1) && board[x2-1][y2+1] >= 0)
            changePossibleMoves(board[x2-1][y2+1], x2-1, y2+1);

        if(validate(x2-2, y2+2) && board[x2-2][y2+2] >= 0)
            changePossibleMoves(board[x2-2][y2+2], x2-2, y2+2);

        if(validate(x1+1, y1-1) && board[x1+1][y1-1] >= 0)
            changePossibleMoves(board[x1+1][y1-1], x1+1, y1-1);

        if(validate(x1+2, y1-2) && board[x1+2][y1-2] >= 0)
            changePossibleMoves(board[x1+2][y1-2], x1+2, y1-2);
    }
}

void Player::update(int from, int to)
{
    int x1 = getX(from);
    int x2 = getX(to);
    int y1 = getY(from);
    int y2 = getY(to);

    board[x1][y1] = -2;
    board[x2][y2] = -1;
    int x = (x1+x2)/2;
    int y = (y1+y2)/2;
    int dx = x2-x1;
    int dy = y2-y1;
    
    // jezlei ruch jest biciem
    if((x1+x2)%2 == 0) 
    {
        int& pos = board[x][y];
        allMoves -= possibleMovesCounter[pos];
        allAttacks -= possibleAttackCounter[pos];
        possibleAttackCounter[pos] = 0;
        possibleMovesCounter[pos] = 0;
        possibleAttack[pos] =0 ;
        possitionOnBoard[pos] = -1;
        possibleMoves[pos] = 0;
        defaultMoves[pos] = 0;
        pos = -2;

        dx = (x2-x1)>>1;
        dy = (y2-y1)>>1; 

        if((dx == 1 && dy == 1) || (dx == -1 && dy == -1))
        {
            crossCheck1(x, y);
        }
        else
        {
            crossCheck2(x, y);
        }
    }
    
    if((dx == 1 && dy == 1) || (dx == -1 && dy == -1))
    {
        changePossibleMoves1(x1, y1, x2, y2, (dx == 1 && dy == 1));
    }
    else
    {
        changePossibleMoves2(x1, y1, x2, y2, (dx == 1 && dy == -1));
    }
}

inline bool Player::validate(int x, int y)
{
    return x >=0 && x < 8 && y >= 0 && y < 8;
}

std::pair<int,int> Player::makeAttack(int idx, int cnt)
{
    int x = getX(possitionOnBoard[idx]);
    int y = getY(possitionOnBoard[idx]);

    if((possibleAttack[idx] & 0b0001) && cnt -- == 0)
    {

        possibleAttack[idx] ^= 0b0001;
        possibleAttackCounter[idx]--;
        allAttacks--;
        attackIdx = idx;
        if(possibleAttackCounter[idx] == 0)
        {
            attackIdx=-1;
            endattack=true;
        }

        return MoveFromTo(x,y,1,1);
    }

    if((possibleAttack[idx] & 0b0010)  && cnt -- == 0)
    {

        possibleAttack[idx] ^= 0b0010;
        possibleAttackCounter[idx]--;
        allAttacks--;
        attackIdx = idx;
        if(possibleAttackCounter[idx] == 0)
        {
            attackIdx=-1;
            endattack=true;
        }

        return MoveFromTo(x,y,1,-1);
    }

    if((possibleAttack[idx] & 0b0100)  && cnt -- == 0)
    {
        possibleAttack[idx] ^= 0b0100;
        possibleAttackCounter[idx]--;
        allAttacks--;
        attackIdx = idx;
        if(possibleAttackCounter[idx] == 0){
            attackIdx=-1;
            endattack=true;
        }

        return MoveFromTo(x,y,-1,-1);
    }

    if((possibleAttack[idx] & 0b1000) && cnt -- == 0)
    {
      
        possibleAttack[idx] ^= 0b1000;
        possibleAttackCounter[idx]--;
        allAttacks--;
        attackIdx = idx;
        if(possibleAttackCounter[idx] == 0)
        {
            attackIdx=-1;
            endattack=true;
        }

        return MoveFromTo(x,y,-1,1);
    }
}

void Player::setAttackParameters(int x, int y)
{
    int idx = board[x][y];

    allAttacks -= possibleAttackCounter[idx];
    possibleAttackCounter[idx] = 0;
    possibleAttack[idx] =0;

    if(validate(x+1,y+1) && validate(x+2,y+2) && board[x+1][y+1] == -1 && board[x+2][y+2] == -2 && (defaultMoves[idx] & 0b0001)) 
    {
        possibleAttack[idx] |= 0b0001;
        possibleAttackCounter[idx]++;
        allAttacks++;
    }

    if(validate(x+1,y-1) && validate(x+2,y-2) && board[x+1][y-1] == -1 && board[x+2][y-2] == -2 && (defaultMoves[idx] & 0b0010)) 
    {
        possibleAttack[idx] |= 0b0010;
        possibleAttackCounter[idx]++;
        allAttacks++;
    }

    if(validate(x-1,y-1) && validate(x-2,y-2) && board[x-1][y-1] == -1 && board[x-2][y-2] == -2 && (defaultMoves[idx] & 0b0100)) 
    {
        possibleAttack[idx] |= 0b0100;
        possibleAttackCounter[idx]++;
        allAttacks++;
    }

    if(validate(x-1,y+1) && validate(x-2,y+2) && board[x-1][y+1] == -1 && board[x-2][y+2] == -2 && (defaultMoves[idx] & 0b1000)) 
    {
       possibleAttack[idx] |= 0b1000;
       possibleAttackCounter[idx]++;
       allAttacks++;
    }

    if(idx == attackIdx && possibleAttackCounter[idx] == 0)
    {
        attackIdx = -1;
        endattack = true;
    }
}

std::pair<int, int> Player::attackAgain()
{
    int pos;
    // jezeli nie wykonalismy jeszcze zadnego bicia to losujemy ze wszystkich mozliwych opcji bicia
    if(attackIdx == -1) 
    {
        pos = randomMove(1, allAttacks);
        int cnt=0;
        for(int i=0;i<12;i++)
        {
            cnt+=possibleAttackCounter[i];
            if(cnt >= pos)
            {
                cnt = cnt - pos;
                return makeAttack(i, cnt);
            }
        }
    }
    // jezeli wykonalismy juz jakies bicie to musimy je kontynuowac 
    else
    {
        pos = randomMove(1, possibleAttackCounter[attackIdx]);
        return makeAttack(attackIdx, pos-1);
    }
}

void Player::changePossibleMoves(int idx, int x, int y)
{
    allMoves -= possibleMovesCounter[idx];
    possibleMovesCounter[idx] = 0;
    possibleMoves[idx] = 0;

    setAttackParameters(x, y);

    //sprawdzamy czy pole na ukos od naszej pozycjy jest wolne lub jesli znajduje sie tam przeciwnik czy pole za nim jest wolne
    if(8 > x+1 && 8 > y+1 && (defaultMoves[idx] & 0b0001))
    {
        if(board[x+1][y+1] == -2 || ((board[x+1][y+1] == -1 &&  (8 > x+2 && 8 > y+2) && board[x+2][y+2] == -2)))
        {
            possibleMoves[idx] |= 0b0001;
            possibleMovesCounter[idx]++;
        }
    }

    if(8 > x+1 && y-1 >= 0 && (defaultMoves[idx] & 0b0010))
    {
        if(board[x+1][y-1] == -2 || ((board[x+1][y-1] == -1 &&  (8 > x+2 && y-2 >= 0) && board[x+2][y-2] == -2)))
        {
            possibleMoves[idx] |= 0b0010;
            possibleMovesCounter[idx]++;
        }
    }

    if(x-1 >=0 && y-1 >= 0 && (defaultMoves[idx] & 0b0100))
    {
        if(board[x-1][y-1] == -2 || ((board[x-1][y-1] == -1 &&  (x-2 >= 0 && y-2 >= 0) && board[x-2][y-2] == -2)))
        {
            possibleMoves[idx] |= 0b0100;
            possibleMovesCounter[idx]++;
        }
    }

    if(x-1 >=0 && 8 > y+1 && (defaultMoves[idx] & 0b1000))
    {
        if(board[x-1][y+1] == -2 || ((board[x-1][y+1] == -1 &&  (x-2 >=0 && 8 > y+2) && board[x-2][y+2] == -2)))
        {
            possibleMoves[idx] |= 0b1000;
            possibleMovesCounter[idx]++;
        }
    }
    
    allMoves += possibleMovesCounter[idx];
}

std::pair<int,int> Player::MoveFromTo(int x,int y, int dx, int dy)
{
    int idx = board[x][y];
   
    // jeżeli miejsce na ktore sie przesuwamy jest wolne, jest to koniec planszy, i mozemy ulepszyc naszego piona do krola 
    if(board[x + dx][y + dy] == -2 && (y + dy == endRegion) && (defaultMoves[idx] ^ 0b1111 != 0)) 
    {
        board[x + dx][y + dy] = idx;
        board[x][y] = -2;
        defaultMoves[idx] = 0b1111;
        changePossibleMoves(idx, x + dx, y + dy);
        possitionOnBoard[idx] = x + dx + 8 * (y+dy);
        if((dx == 1 && dy == 1) || (dx == -1 && dy == -1))
        {
            changePossibleMoves1(x, y, x + dx, y + dy, (dx == 1 && dy == 1));
        }
        else
        {
            changePossibleMoves2(x, y, x + dx, y + dy, (dx == 1 && dy == -1));
        }
        
        return std::make_pair(x+y*8, x+dx + (y+dy)*8);
    }
    // jeżeli miejsce na ktore sie przesuwamy jest wolne
    else if(board[x + dx][y + dy] == -2) 
    {
        board[x + dx][y + dy] = idx;
        board[x][y] = -2;
        changePossibleMoves(idx, x + dx, y + dy);
        possitionOnBoard[idx] = x + dx + 8 * (y+dy);
        if((dx == 1 && dy == 1) || (dx == -1 && dy == -1))
        {
            changePossibleMoves1(x, y, x + dx, y + dy, (dx == 1 && dy == 1));
        }
        else
        {
            changePossibleMoves2(x, y, x + dx, y + dy, (dx == 1 && dy == -1));
        }

        return std::make_pair(x+y*8, x+dx + (y+dy)*8);
    }
    // jeżeli wykonujemy bicie
    else if(board[x + dx][y + dy] == -1 && board[x + 2*dx][y +2*dy] == -2) 
    {
        board[x + 2*dx][y +2*dy] = idx;
        board[x + dx][y + dy] = -2;
        board[x][y] = -2;
        changePossibleMoves(idx, x + 2*dx, y + 2*dy);
        possitionOnBoard[idx] = x + 2*dx + 8 * (y+2*dy);
        if((dx == 1 && dy == 1) || (dx == -1 && dy == -1))
        {
            crossCheck1(x + dx, y + dy);
            changePossibleMoves1(x, y, x + 2*dx, y + 2*dy, (dx == 1 && dy == 1));
        }
        else
        {
            crossCheck2(x + dx, y + dy);
            changePossibleMoves2(x, y, x + 2*dx, y + 2*dy, (dx == 1 && dy == -1));
        }

        return std::make_pair(x+y*8, x+2*dx + (y+2*dy)*8);
    }
}

std::pair<int,int> Player::makeMove(int idx, int cnt)
{
    int x = getX(possitionOnBoard[idx]);
    int y = getY(possitionOnBoard[idx]);

    int posm = possibleMoves[idx];  

    if((posm & 0b0001) && cnt-- == 0)
    {
        return MoveFromTo(x,y,1,1);
    }

    if((posm & 0b0010) && cnt-- == 0)
    {
        return MoveFromTo(x,y,1,-1);
    }

    if((posm & 0b0100) && cnt-- == 0)
    {
        return MoveFromTo(x,y,-1,-1);
    }
    
    if((posm & 0b1000) && cnt-- == 0)
    {
        return MoveFromTo(x,y,-1,1);
    }
}

std::pair<int,int> Player::move()
{
    int pos = randomMove(1, allMoves);
    int cnt=0;
    for(int i=0;i<12;i++)
    {
        cnt+=possibleMovesCounter[i];
        if(cnt >= pos)
        {
            cnt = cnt - pos;
            return makeMove(i, cnt);
        }
    }
}

int Player::randomMove(int from, int to)
{
    static std::random_device rd; 
    static std::mt19937 generator(rd());

    std::uniform_int_distribution<int> dist(from ,to);
    return dist(generator);
}

void Player::printMoves(int* tab, int* tabCnt, int d, int s, int e)
{
    for(int i=s;i<=e;i++)
    {
        int x,y;
        if(tabCnt[i] > 0)
        {
            x = getX(possitionOnBoard[i]);
            y = getY(possitionOnBoard[i]);
            if(tab[i] & 0b0001)
            {
                std::cout << x << " " << y << " -> " << x+d << " " << y+d << "\n";
            }

            if(tab[i] & 0b0010)
            {
                std::cout << x << " " << y << " -> " << x+d << " " << y-d << "\n";
            }

            if(tab[i] & 0b0100)
            {
                std::cout << x << " " << y << " -> " << x-d << " " << y-d << "\n";
            }

            if(tab[i] & 0b1000)
            {
                std::cout << x << " " << y << " -> " << x-d << " " << y+d << "\n";
            }
        }
    }
}

void Player::displayPossibleMoves()
{
    // jezeli musimy bic nasze jedyne dostepne ruchy to te ktore sa atakujace
    if(needToAttack())
    {
        if(attackIdx == -1) 
        {
            printMoves(possibleAttack, possibleAttackCounter, 2, 0, 11);
        }
        // jezeli wykonalismy juz jakies bicie to musimy je kontynuowac 
        else
        {
            printMoves(possibleAttack, possibleAttackCounter, 2, attackIdx, attackIdx);
        }
    }
    else
    {
        printMoves(possibleMoves, possibleMovesCounter, 1, 0, 11);
    }
}