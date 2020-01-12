#ifndef GAME_H
#define GAME_H

#include"blackplayer.h"
#include"whiteplayer.h"

class Game
{
private:
    void endgame(int& state);

public:
    Game();
    void start();
    
};

#endif // GAME_H
