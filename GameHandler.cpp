#include "GameHandler.hpp"

void GameHandler::step_forward(CurrentState* game_state)
{
    print_scene(game_state, std::cout);
    read_move(game_state);
}

/*
* Prints current scene to output stream and receives user input.
* TODO: remove reference to ostream, no longer needed
*/
void GameHandler::print_scene(CurrentState* game_state, std::ostream& out)
{
    game_state->get_cur_menu()->displayMenu();
    game_state->get_cur_menu()->get_input();
}

/*
* Checks for indication of scene change and acts accordingly.
*/
void GameHandler::read_move(CurrentState* game_state)
{
    // TODO: to be implemented
    // if game_state->current_menu->get_next_menu_id() > 0
    //     move_scene(game_state, game_state->current_menu->get_next_menu_id())
}

/*
* Moves game state to new scene and updates the current menu.
*/
void GameHandler::move_scene(CurrentState* game_state, int m_id)
{
    delete game_state->get_cur_menu();
    game_state->update_cur_menu(gen_menu_from_id(game_state, m_id));
}

void GameHandler::exit_game(CurrentState* game_state)
{
    game_state->update_game_status(game_status::status_stop);
}

void GameHandler::clean_up(CurrentState* game_state)
{

}

/* ========== Helper Functions ========================= */
Menu* GameHandler::gen_menu_from_id(CurrentState* game_state, int m_id)
{
    Menu* g_menu = nullptr;

    switch (m_id)
    {
    case menu_id::menu_idle:
        g_menu = new BaseMenu(game_state);
        break;
    case menu_id::menu_combat:
        g_menu = new CombatMenu(game_state);
        break;
    case menu_id::menu_class:
        g_menu = new ClassSelect(game_state);
        break;
    case menu_id::menu_shop:
        g_menu = new ShopMenu(game_state);
        break;
    }

    return g_menu;
}


/* ===== DEPRECIATED FUNCTIONS =====
*
* Reads from input stream and calls the appropriate function
* to process the input.
* TODO: decide how it chooses the correct function
*
void GameHandler::read_input(CurrentState* game_state, std::istream& in)
{
    std::string* in_str = new std::string(in->rdbuf());

    // currently menu input is the only option
    receive_menu_input(game_state, in_str);
}

* 
* Processes input string and gives it to the game state.
* Will catch non-int and negative inputs but will NOT check if
* the input is in range (eg too large).
* 
* Will pass -1 to game state if input is invalid.
*
void GameHandler::receive_menu_input(CurrentState* game_state, std::string in_str)
{
    int in_num = 0;
    
    try
    {
        // try read input as int
        in_num = std::stoi(in_str, nullptr, 10);
        if (in_num < 0) throw std::invalid_argument();
    }
    catch(std::invalid_argument bad_num)
    {
        in_num = -1;
    }

    // TODO: update functionality of update_cur_menu
    game_state->update_cur_menu(in_num);
}
*/

