#pragma once

#include <array>
#include "Debug.h"

class Input {
public:
    Input();
    ~Input();

    void update(bool val, int key);
    bool getState(int key);

    void DSerializeData();

private:
    std::array<bool, 227> inputDeck;

    Debug_ *deb;
};

