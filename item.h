#ifndef _ITEM_H__
#define _ITEM_H__

#include <iostream>
#include <vector>
#include <string>

#include "inventory.h"





class Item 
{
    protected:
	    std::string itemName = "";
		int itemSerial = 0;
		
	public:
		std::string get_item_name() { return itemName; }
		
		virtual ~Item(){}

		virtual void use() = 0;
		
		int getItemSerial () const {
			return itemSerial;
		}

};

class HealthPot : public Item
{
    protected:
	    int heal_amount = 10;
		int itemSerial = 1;

	public:

		HealthPot(){
			itemName = "Health Potion";
		}

		 ~HealthPot(){}

		virtual void use(){
			
           
			
		  // if (hp >= max_hp){
			  // hp = max_hp;
		  // }
        }

};

class LargeHPot : public Item
{
    protected:
	    int heal_amount = 20;
		int itemSerial = 2;

	public:
		LargeHPot(){
			itemName = "Large Healing Potion";
		}

		 ~LargeHPot(){}

		virtual void use(){
           // hp += heal_amount ;
		   // if (hp >= max_hp){
			  // hp = max_hp;
		  // }
        }

};

class ManaPot : public Item
{
    protected:
	    int recover_amount = 10;
		int itemSerial = 3;

	public:
		ManaPot(){
			itemName = "Mana Potion";
		}

		 ~ManaPot(){}

		virtual void use(){
            //mp += recover_amount;
			// if (mp >= max_mp){
			  // mp = max_mp;
		  // }
        }

};

class LargeMPot : public Item
{
    protected:
	    int recover_amount = 20;
		int itemSerial = 4;

	public:
		LargeMPot(){
			itemName = "Large Mana Potion";
		}

		 ~LargeMPot(){}

		virtual void use(){
           // mp += recover_amount;
		   // if (mp >= max_mp){
			  // mp = max_mp;
		  // }
        }

};

class HalfHalfPotion : public Item
{
    protected:
	    int recover_amount = 5;
		int heal_amount = 5;
		int itemSerial = 5;

	public:

		HalfHalfPotion(){
			itemName = "Half & Half Potion";
		}
		 ~HalfHalfPotion(){}

		virtual void use(){
			//hp += heal_amount ;
            //mp += recover_amount;
			// if (hp >= max_hp){
			  // hp = max_hp;
		  // }
			//if (mp >= max_mp){
			  // mp = max_mp;
		  // }
        }

};



class ItemBag : public Item
{
    protected:
        static const int MAXSTACKSIZE = 10;
		int itemSerial = 10;
	   
	    //std::vector<Item>* item_list;

	public:
		 ~ItemBag(){}

		virtual void use(){
          //  for (auto i : *item_list){
                //		std::cout << i << "\n";
            	//	}
        }

};



#endif 