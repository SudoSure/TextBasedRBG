#ifndef _SHOPKEEPER_H__
#define _SHOPKEEPER_H__

#include <iostream>
#include <vector>
#include <string>

#include "inventory.h"


class Shopkeeper 
{
    protected:
	    Inventory* shop_inv;
        int shop_gold;

	public:
		virtual ~Shopkeeper(){}

		void displayInventory(){
          //  for (auto i : *inventory_list){
            //    		std::cout << i << "\n";
            //}
        }

        //void buyItem(){}

        //nt checkValue(){}

};




#endif 