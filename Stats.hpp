#pragma once
#ifndef STATS_HPP
#define STATS_HPP

#include <string>

/* ========== Stats Localization ======================= */
static const std::string STR_LOC = "strength";
static const std::string DEX_LOC = "dexterity";
static const std::string BRAIN_LOC = "intelligence";

/*
* Basic stat block for entity
*/
class Stats
{
private:
    int str;
    int dex;
    int brain;

public:
    Stats()
    {
        str, dex, brain = 10;
    }
    
    Stats(int s, int d, int b)
        : str(s), dex(d), brain(b) {};

    void set_str(int s) { this->str = s; }
    void set_dex(int d) { this->dex = d; }
    void set_brain(int b) { this->brain = b; }

    int get_str() { return this->str; }
    int get_dex() { return this->dex; }
    int get_brain() { return this->brain; }

    /* ===== DEPRECIATED FUNCTIONS =====
    const std::string& get_str_loc() { return STR_LOC; }
    const std::string& get_dex_loc() { return DEX_LOC; }
    const std::string& get_brain_loc() { return BRAIN_LOC; }
    */
};

#endif // STATS_HPP