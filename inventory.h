#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>
#include "item.h"


class Inventory
{
    protected:
	static const int MAXITEMS = 100;
	static const int MAXGOLD = 10000000;

	int largeHPNum = 0;
	int HPNum = 0;
	int largeMPNum = 0;
	int MPNum = 0;
	int HHNum = 0;

    std::vector<Item*> contents;
  
	public:
		
		~Inventory()
		{
			for (auto i : contents)
				delete i;
		}

		void displayInventory(){
			for (auto i : contents)
				std::cout << i->get_item_name() << "\n";
       	}

		void add(Item* i)
		{
			// only add if inventory is not full
			if (contents.size() < 100)
				contents.push_back(i);
			else std::cout << "Inventory is full!\n";
		}

		// removes the ith element of the contents vector, starting at 1
		void remove(int i)
		{
			// only works if i is a valid entry
			if ((i - 1) < contents.size() && (i - 1) >= 0)
				contents.erase(contents.begin() + (i + 1));
			else std::cout << "Invalid item!\n";
		}

		// accesses the ith element of the contents vector, starting at 1
		Item* access_item(int i)
		{
			Item* item_ptr = nullptr;

			// only works if i is a valid entry
			if ((i - 1) < contents.size() && (i - 1) >= 0)
				item_ptr = contents.at(i - 1);
			return item_ptr;
		}

		//getter functions
		int getLargeHPNum(){
			return largeHPNum;
		}
		int getHPNum(){
			return HPNum;
		}
		int getLargeMPNum(){
			return largeMPNum ;
		}
		int getMPNum(){
			return MPNum;
		}
		int getHHNum(){
			return HHNum;
		}

		//setter functions
		void setLargeHpNum (int n){
			largeHPNum = n;
		}

		void setHPNum (int n){
			HPNum = n;
		}

		void setLargeMPNum (int n){
			largeMPNum = n;
		}

		void setMPNum (int n){
			MPNum= n;
		}

		void setHHNum (int n){
			HHNum = n;
		}

};

#endif // INVENTORY_H