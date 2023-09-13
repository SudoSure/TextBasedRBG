/*
* GameHandler - contains the functions which make the game run
*/

#pragma once
#ifndef GAMEHANDLER_HPP
#define GAMEHANDLER_HPP

#include "CurrentState.hpp"
#include "menu.h"
#include <iostream>
#include <sstream>
#include <string>

class GameHandler
{
public:
    GameHandler() {}

    void step_forward(CurrentState* game_state);
    void print_scene(CurrentState* game_state, std::ostream& out);
    void read_move(CurrentState* game_state);
    void move_scene(CurrentState* game_state, int m_id);
    void exit_game(CurrentState* game_state);
    void clean_up(CurrentState* game_state);

    // helper
    Menu* gen_menu_from_id(CurrentState* game_state, int m_id);

    // ===== DEPRECIATED FUNCTIONS =====
    // void read_input(CurrentState* game_state, std::istream& in);
    // void receive_menu_input(CurrentState* game_state, std::string in_str);
};

/*
* Encapsulates information passed from user input to various other places.
* TODO: not sure if this is needed, maybe get rid of it
*/
class InputInfo
{
private:
    int in_data;
};

#endif // GAMEHANDLER_HPP