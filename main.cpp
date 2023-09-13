#include "CurrentState.hpp"
#include "GameHandler.hpp"
#include "menu.h"

int main(int argc, char* argv[])
{
    GameHandler g_handler;
    CurrentState g_state;

    g_handler.move_scene(&g_state, menu_id::menu_class);     // start on class selection menu

    // while game is running, perform regular actions
    while (!(g_state.get_status() < game_status::status_initial))
    {
        g_handler.step_forward(&g_state);
    }

    g_handler.clean_up(&g_state);

  
  
    return 0;
}
