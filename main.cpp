#include <chrono>

#include "game.h"

using namespace std;
using namespace std::chrono;
int main()
{
    ios_base::sync_with_stdio(false);
    auto start = high_resolution_clock::now(); 
    for(int i=0;i<100000;i++)
    {
        Game game;
        game.start();
    }
    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "time needed to finish 100000 games: " << duration.count() << " microseconds" << endl; 

    return 0;
}