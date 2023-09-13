/*
* Entity - base class for Monster and PlayerClass
*/

#pragma once
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Stats.hpp"
#include <string>

class Entity
{
protected:
    std::string name;
    int max_hp;
    int max_mp;
    int hp;
    int mp;
    Stats* char_stats = nullptr;

    virtual void init_stats() { this->char_stats = new Stats(); }
public:
    Entity()
    {
        init_stats();
    }

    ~Entity()
    {
        delete char_stats;
    }

    virtual void takeDmg(int atk_val, Entity* origin) = 0;
    virtual int dealDmg(int atk_val, Entity* target) = 0;
    void useMP(int val)
    {
        mp -= val;

        // last safeguard against negative mp values. should still check on
        // skill use.
        if (mp < 0) mp = 0;
    }

    // getters
    std::string get_name() { return this->name; }
    int get_max_hp() { return this->max_hp; }
    int get_max_mp() { return this->max_mp; }
    int get_hp() { return this->hp; }
    int get_mp() { return this->mp; }
    Stats* get_stats() { return this->char_stats; }
};

#endif // ENTITY_HPP