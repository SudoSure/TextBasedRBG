/*
* Player - contains information and functions regarding the player
*/

#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "PlayerClass.hpp"
#include "inventory.h"

class Player
{
private:
    PlayerClass* p_class = nullptr;
    Inventory* p_inv = nullptr;
    int p_gold = 0;
public:
    Player()
    {
        this->p_inv = new Inventory();
    }

    ~Player()
    {
        delete p_class;
        delete p_inv;
    }

    void give_gold(int val) { this->p_gold += val; }
    void spend_gold(int val)
    {
        this->p_gold -= val;

        // last safeguard against negative gold, but should still
        // check if there is enough gold when trying to spend.
        if (p_gold < 0) p_gold = 0;
    }

    // getters
    PlayerClass* get_class() { return this->p_class; }
    Inventory* get_inv() { return this->p_inv; }
    int get_gold() { return this->p_gold; }

    // setters
    void set_class(PlayerClass* pc) { this->p_class = pc; }
};

#endif // PLAYER_HPP