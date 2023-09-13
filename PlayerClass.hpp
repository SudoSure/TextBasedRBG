#pragma once
#ifndef PLAYERCLASS_HPP
#define PLAYERCLASS_HPP

#include "Entity.hpp"
#include <string>
#include <vector>

class PlayerClass;

/*
* Holds information regarding attacks made by the player
*/
struct Attack
{
    int value = 0;                  // damage or healing amount
    std::string loc = "";           // name of attack
    PlayerClass* origin = nullptr;  // source of attack

    // constructor for attack with exact defined value
    Attack(int v, PlayerClass* o) : value(v), origin(o) {};

    // constructor for attack with approximate range of potential values
    Attack(int mid, int range, PlayerClass* o) : origin(o)
    {
        value = rand() % (range + 1) + (mid - (range / 2));
        if (value < 1) value = 1;   // ensure value is never below 1
    };
};

/*
* Interface for behavior of player classes, contains layout for
* attacks and abilities which is universal across all classes.
*/
class Class_Behavior
{
public:
    /*
    * Returns Attack pointer, calculated after stat modifiers but
    * before equipment modifiers.
    */
    virtual Attack* attack_basic(Entity* target) = 0;
    virtual Attack* attack_alt(Entity* target) = 0;
    virtual Attack* p_skill(Entity* target, int m_cost) = 0;
};

/*
* PlayerClass - represents functions and attributes shared by all player
* classes. Should not be instantiated directly on its own, but through one
* of the subclasses.
*/
class PlayerClass : public Entity, public Class_Behavior
{
protected:
    std::vector<Attack*> atk_history;
    std::string class_name;

    void process_atk(Attack* out_atk, Entity* target);
public:
    ~PlayerClass();

    void takeDmg(int atk_val, Entity* origin);
    int dealDmg(int atk_val, Entity* target);
    std::string get_cname() { return this->class_name; };
};

/* ========== PlayerClass Subclasses =================== */
class Knight : public PlayerClass
{
protected:
    void init_stats() { this->char_stats = new Stats(16, 10, 10); }
public:
    Knight() { class_name = "Knight"; }

    Attack* attack_basic(Entity* target);
    Attack* attack_alt(Entity* target);
    Attack* p_skill(Entity* target, int m_cost);
};

class Archer : public PlayerClass
{
protected:
    void init_stats() { this->char_stats = new Stats(10, 16, 10); }
public:
    Archer() { class_name = "Archer"; }

    Attack* attack_basic(Entity* target);
    Attack* attack_alt(Entity* target);
    Attack* p_skill(Entity* target, int m_cost);
};

class Mage : public PlayerClass
{
protected:
    void init_stats() { this->char_stats = new Stats(10, 10, 16); }
public:
    Mage() { class_name = "Mage"; }

    Attack* attack_basic(Entity* target);
    Attack* attack_alt(Entity* target);
    Attack* p_skill(Entity* target, int m_cost);
};

#endif // PLAYERCLASS_HPP