#include "Game.h"

Game::Game(Debug_ *deb)
{
    inputMan = new Input();
    this->deb = deb;
}

void Game::update()
{
}

void Game::procInput(bool val, int key)
{
    inputMan->update(val, key);
}