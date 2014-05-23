/****************************************************
              MAIN GAME HEADER FILE

Game loop calls the public functions here at a fixed
interval. The entire bootstrap and gameplay is fired
from private function calls.
****************************************************/

#include <list>

#include "Input.h"
#include "Debug.h"

class Input;
class Debug_;

class Game {
public:
    Game(Debug_ *deb);

    ~Game()
    {
    }

    void update();
    void procInput(bool val, int key);

private:
    Input *inputMan;
    Debug_ *deb;
};

