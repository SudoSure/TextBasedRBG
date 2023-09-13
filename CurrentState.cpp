#include "CurrentState.hpp"

void CurrentState::init()
{
    update_game_status(game_status::status_run);
}

/*
* Sets current_menu to the menu referenced by given pointer. Ensure that
* the old menu is properly deleted if appropriate.
*/
void CurrentState::update_cur_menu(Menu* upd_menu)
{
    this->current_menu = upd_menu;
}

void CurrentState::update_cur_player(Player* upd_player)
{
    this->current_player = upd_player;
}

void CurrentState::update_game_status(int g_status)
{
    status = g_status;
}