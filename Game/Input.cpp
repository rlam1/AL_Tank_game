#include "Input.h"

Input::Input()
{
    inputDeck.fill(false);
    this->deb = new Debug_("keyState.txt", false);
}


Input::~Input()
{
}

void Input::update(bool val, int key)
{
    inputDeck[key] = val;
}

bool Input::getState(int key)
{
    return inputDeck[key];
}

void Input::DSerializeData()
{
    int counter = 0;

    deb->log_("STARTING SERIALIZATION", "...");

    for (auto input : inputDeck)
    {
        std::string key;

        key.append(deb->intToStr(counter).c_str());
        key.append(" key value:");

        deb->log_(key, deb->boolToStr(input));
        counter++;
    }

    deb->log_("SERIALIZATION SUCCESSFUL", "!!!");
}
