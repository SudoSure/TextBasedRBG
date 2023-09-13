/*
* CurrentState and some of its dependencies
*/

#pragma once
#ifndef CURRENTSTATE_HPP
#define CURRENTSTATE_HPP

#include "Player.hpp"

class Menu;

/* ========== Game Status IDs ========================== */
namespace game_status
{
    const int status_initial = 0;
    const int status_run = 1;
    const int status_stop = -1;
}

/* ========== Menu IDs ================================= */
namespace menu_id
{
    const int menu_current = -1;
    const int menu_idle = 0;
    const int menu_combat = 1;
    const int menu_class = 2;
    const int menu_shop = 3;
}

/*
* CurrentState - keeps track of everything going on in the game,
* including current menu, player, and run status of the game.
*/
class CurrentState
{
private:
    Menu* current_menu = nullptr;
    Player* current_player = nullptr;
    int status = game_status::status_initial;

    void init();
public:
    CurrentState() { init(); }

    // getters
    Menu* get_cur_menu() { return current_menu; }
    Player* get_cur_player() { return current_player; }
    int get_status() { return status; }

    // setters
    void update_cur_menu(Menu* upd_menu);
    void update_cur_player(Player* upd_player);
    void update_game_status(int g_status);
};


#endif // CURRENTSTATE_HPP