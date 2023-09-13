#ifndef _MENU_H__
#define _MENU_H__

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Player.hpp"
#include "CurrentState.hpp"
#include "PlayerClass.hpp"
#include "inventory.h"
#include "monster.hpp"

using namespace std;
/*
 *  *  * Strategy
 *   *   * declares an interface common to all supported algorithms
 *    *    * */

class Menu
{
    protected:
		CurrentState* playerState;
		int next_menu_id = menu_id::menu_current;

	public:
		virtual ~Menu(){}

		Menu() : playerState(nullptr) {}
		
		Menu(CurrentState* const &currState) : playerState(currState) {}

		virtual void displayMenu() = 0;

        virtual void get_input() = 0;

		int get_next_menu_id() { return next_menu_id; }
};

class BaseMenu : public Menu
{	
	private:
        std::vector<std::string> base_list {"1: Hunt","2: Shop","3: Inventory","4. Quit"};

	public:
		BaseMenu(CurrentState* const &g) : Menu(g) {}
		~BaseMenu() {}

		void displayMenu(){
            for (auto i : base_list){
                std::cout << i << "\n";
            }
        }

        void displayGreeting(){
            std::cout << "Welcome to our game!" << std::endl;
        }

		void get_input(){
			int in;
			std::cout<<"Please choose an option: ";

			bool is_valid = false;

			
			while (is_valid == false)
			{
				is_valid = true;
				
				std::cin >> in;

				switch (in)
				{
				case 1:
					std::cout << "Looking for monsters to fight..." << std::endl;
					this->next_menu_id = menu_id::menu_combat;
					break;
				case 2:
					std::cout << "Opening the shop..." << std::endl;
					this->next_menu_id = menu_id::menu_shop;
					break;
				case 3:
					std::cout << "Player Inventory: " << std::endl;
					playerState->get_cur_player()->get_inv()->displayInventory();
					this->get_input();
					break;
				case 4:
					std::cout << "Are you sure you want to quit? (Y/N) :";
					char userQuit;
					std::cin >> userQuit;
						if(userQuit == 'Y' || userQuit == 'y'){
							exit(0);
						}
						else if (userQuit == 'N' || userQuit == 'n'){
							is_valid == false;
						}
						else{
							while (userQuit != ('Y','y','N','n'))
							std::cout << "Please enter Y or N :";
							std::cin >> userQuit;
						}
					

				default:
					is_valid = false;
					std::cout << "Please enter a valid response: ";
				}
			}

		}
};

class CombatMenu : public Menu
{ 
	private:
        std::vector<std::string> combat_list{"1: Attack","2: Alt Attack","3: Skill","4: Inventory","5. Retreat"};
		monster* monster;

	public:
        CombatMenu(CurrentState* const &g) : Menu(g) {
			srand(time(0));
			int randNum = (rand() % 4) + 1;

			switch(randNum){
				case 1:
					monster = new Easy("Weak Monster");
					break;

				case 2:
					monster = new Normal("Normal Monster");
					break;

				case 3:
					monster = new Hard("Strong Monster");
					break;

				case 4:
					monster = new Boss("Boss");
					break;
			}
		}

		~CombatMenu(){
			delete monster;
		}

		void displayMenu(){
            for (auto i : combat_list){
                std::cout << i << "\n";
            }
        }

		void get_input() {
			int in;
			std::cout<<"Please choose an option: ";

			bool is_valid = false;

			
			while (is_valid == false)
			{
				is_valid = true;
				
				std::cin >> in;
				int item_num = 0; // for inventory use
				int serialNum = 0;

				switch (in)
				{
				case 1:
					playerState->get_cur_player()->get_class()->attack_basic(monster);

					if (monster->isAlive()){
						this->get_input();
						break;
					}
					else if (!monster->isAlive()){
						playerState->get_cur_player()->give_gold(monster->goldDrop());
						this->next_menu_id = menu_id::menu_idle;

						break;
					}

				case 2:
					playerState->get_cur_player()->get_class()->attack_alt(monster);

					if (monster->isAlive()){
						this->get_input();
						break;
					}
					else if (!monster->isAlive()){
						playerState->get_cur_player()->give_gold(monster->goldDrop());
						this->next_menu_id = menu_id::menu_idle;
						break;
					}

				case 3:
					// TODO: possibly make mana cost different between classes
					playerState->get_cur_player()->get_class()->p_skill(monster, 50);

					if (monster->isAlive()){
						this->get_input();
						break;
					}
					else if (!monster->isAlive()){
						playerState->get_cur_player()->give_gold(monster->goldDrop());
						this->next_menu_id = menu_id::menu_idle;
						break;
					}

				case 4:
					std::cout << "Player Inventory: " << std::endl;
					playerState->get_cur_player()->get_inv()->displayInventory();

					// TEMPORARY CODE
					std::cout << "Which item would you like to use? (Choose a number) ";

					std::cout<<"1:  HP Potion "<<"\n";
					std::cout<<"2:  LargeHP potion"<<"\n";
					std::cout<<"3:  MP Potion "<<"\n";
					std::cout<<"4:  Large MP potion "<<"\n";
					std::cout<<"5: Half and Half Potion "<<"\n";
					
					std::cin >> item_num;

					while (item_num > 5 || item_num < 1){
						std::cout << "Which item would you like to use? (Choose a number) ";

						std::cout<<"1:  HP Potion "<<"\n";
						std::cout<<"2:  LargeHP potion"<<"\n";
						std::cout<<"3:  MP Potion "<<"\n";
						std::cout<<"4:  Large MP potion "<<"\n";
						std::cout<<"5: Half and Half Potion "<<"\n";
					
						std::cin >> item_num;
					}

					playerState->get_cur_player()->get_inv()->access_item(item_num);

				
					
					//if (item_num == 1){
						
					//}else if (item_num == 2){

					//}else if (item_num == 3){

					//}else if(item_num == 4){

					//}else if (item_num == 5){

					//}

					this->next_menu_id = menu_id::menu_current;
					break;
				case 5:
					std::cout << "You manage to get away safely... " << std::endl;
					break;
				default:
					is_valid = false;
					std::cout << "Please enter a valid response: ";
				}
			}
		}
};

class ClassSelect: public Menu
{
	private:
        std::vector<std::string> cselect_list {"1: Knight","2: Mage", "3: Archer"
		};
	public:
		ClassSelect(CurrentState* const &g) : Menu(g) {}

		~ClassSelect() {	}

		void displayMenu(){
			std::cout << "The following classes are available: \n";

			for( auto i : cselect_list){
				std::cout<< i <<"\n";
			}
		}

		void get_input(){
			int in;
			std::cout<<"Please select your class: ";

			bool is_valid = false;

			
			while (is_valid == false)
			{
				is_valid = true;
				
				std::cin >> in;

				switch (in)
				{
				case 1:
					std::cout << "You have chosen the Knight Class!" << std::endl;
					this->playerState->get_cur_player()->set_class(new Knight());
					break;
				case 2:
					std::cout << "You have chosen the Archer Class!" << std::endl;
					this->playerState->get_cur_player()->set_class(new Archer());
					break;
				case 3:
					std::cout << "You have chosen the Mage Class!" << std::endl;
					this->playerState->get_cur_player()->set_class(new Mage());
					break;
				default:
					is_valid = false;
					std::cout << "Please enter a valid response: ";
				}
			}

			
			this->next_menu_id = menu_id::menu_idle;
		}
};

class ShopMenu: public Menu
{
	private:
		std::vector<std::string>shop_list{"1: Buy", "2: Inventory", "3: Go back to Base menu"};
		
	public:
		ShopMenu(CurrentState* g) : Menu(g) {}
		~ShopMenu(){}

		void displayMenu(){
			for( auto i : shop_list){
				std::cout<< i <<"\n";
			}
		}	
		void get_input(){

			int in;
			std::cout<<" Please select an option: ";
			bool is_valid = false;

			while(!is_valid){

				is_valid = true;

				std::cin >>in;

				switch(in)
				{
					case '1':
						buy();
						break;
					case '2':
						std::cout << "Player Inventory: " << std::endl;
						playerState->get_cur_player()->get_inv()->displayInventory();
						this->next_menu_id = menu_id::menu_current;
						break;
					case '3':
						std::cout <<"Going back to Base Menu"<<std::endl;
						this->next_menu_id = menu_id::menu_idle;
						break;
					default:
						is_valid= false;
						std::cout<<"Please enter valid option: ";

				}	

			}
		}
				
	void buy(){
		std::cout<<"===== SHOP ======"<<"\n";
		std::cout<<"1: Large HP Potion (50 gold)"<<"\n";
		std::cout<<"2: HP potion (30 gold)"<<"\n";
		std::cout<<"3: Large MP Potion (50 gold)"<<"\n";
		std::cout<<"4: MP potion (30 gold)"<<"\n";
		std::cout<<"5: Half and Half Potion (40 gold)"<<"\n";
		std::cout<<"6: Back to Base menu"<<"\n";
		std::cout<<"Which item do you want to buy?"<<"\n";

		int input1;
		bool is_valid = false;

		while(!is_valid){

			is_valid = true;

			std::cin >> input1;

			switch(input1)
			{
				case 1:
					std::cout << "You have purchased 1 Large HP Potion!" << std::endl;
					playerState->get_cur_player()->get_inv()->largeHPNum++;
					std::cout << "You now have " << playerState->get_cur_player()->get_inv()->largeHPNum << " Large HP Potion(s)." << std::endl;
					this->next_menu_id = menu_id::menu_current;
					break;

				case 2:
					std::cout << "You have purchased 1 HP Potion!" << std::endl;
					playerState->get_cur_player()->get_inv()->HPNum++;
					std::cout << "You now have " << playerState->get_cur_player()->get_inv()->HPNum << " HP Potion(s)." << std::endl;
					this->next_menu_id = menu_id::menu_current;
					break;

				case 3:
					std::cout << "You have purchased 1 Large MP Potion!" << std::endl;
					playerState->get_cur_player()->get_inv()->largeMPNum++;
					std::cout << "You now have " << playerState->get_cur_player()->get_inv()->largeMPNum << "Large MP Potion(s)." << std::endl;
					this->next_menu_id = menu_id::menu_current;
					break;

				case 4:
					std::cout << "You have purchased 1 MP Potion!" << std::endl;
					playerState->get_cur_player()->get_inv()->MPNum++;
					std::cout << "You now have " << playerState->get_cur_player()->get_inv()->MPNum << " MP Potion(s)." << std::endl;
					this->next_menu_id = menu_id::menu_current;
					break;

				case 5:
					std::cout << "You have purchased 1 Half and Half Potion!" << std::endl;
					playerState->get_cur_player()->get_inv()->HHNum++;
					std::cout << "You now have " << playerState->get_cur_player()->get_inv()->HHNum << " Half and Half Potion(s)." << std::endl;
					this->next_menu_id = menu_id::menu_current;
					break;

				case 6:
					std::cout << "Returning to Base Menu!" << std::endl;
					this->next_menu_id = menu_id::menu_idle;
					break;

				default:
					is_valid= false;
					std::cout<<"Please enter valid option: ";
			}	

		}
	}
};

#endif //_MENU_H__
