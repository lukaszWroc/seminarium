#include "game.h"

Game::Game() 
{
}

void Game::start()
{
    Player* blackplayer = new BlackPlayer;
    Player* whiteplayer = new WhitePlayer;

    Player *player = whiteplayer;
    int playerState = -1;
    std::pair<int,int> fromTo;
    bool check;

    while(true)
    {
        if(!player->isAbleToMove())
        {
            endgame(playerState);
            break;
        }

        check = false;

        while(player->needToAttack())
        {
            fromTo = player->attackAgain();
            if(playerState == -1)
            {    
                blackplayer->update(fromTo.first, fromTo.second);
            }
            else
            {
                whiteplayer->update(fromTo.first, fromTo.second);
            }
            check = true;
        }

        if(check)
        {
            if(playerState == -1)
            {
                player = blackplayer;
                playerState = 1;
            }
            else
            {
                player = whiteplayer;
                playerState = -1;
            }   
            continue;
        }

        fromTo = player->move();

        if(playerState == -1)
        {
            blackplayer->update(fromTo.first, fromTo.second);
            player = blackplayer;
            playerState = 1;
        }
        else
        {
            whiteplayer->update(fromTo.first, fromTo.second);
            player = whiteplayer;
            playerState = -1;
        }
    }

    delete blackplayer;
    delete whiteplayer;
}

void Game::endgame(int& playerState)
{
    // std::cout << "player " << (playerState == 1 ? "black" : "white") << " won!\n";
}

