#ifndef MONSTER_HPP
#define MONSTER_HPP

#include "Entity.hpp"
#include<string>
#include<stdlib.h>

using namespace std;

class monster : public Entity{
protected:
	int damageMin;
	int damageMax;

	void init_stats();
public:
	monster(string n);
	~monster();

	inline bool isAlive() {
		return this->hp > 0; 
	}
	
	void takeDmg(int damage, Entity* origin){ 
		this->hp -= damage;
	}
	int dealDmg(int damage, Entity* target) { 
		return rand() % (this->damageMax - this->damageMin + 1) + this->damageMin;
	}
	inline virtual int goldDrop()const {return 100;}

	/* ===== DEPRECIATED FUNCTIONS =====
	std::string char_stats()const;
	*/
};

class Easy : public monster {
private:
	void init_stats();
public:
	Easy(string n);
	inline int goldDrop()const { return 100;}
};

class Normal : public monster {
private:
	void init_stats();
public:
	Normal(string n);
	inline int goldDrop()const { return 200;}
};

class Hard : public monster {
private:
	void init_stats();
public:
	Hard(string n);
	inline int goldDrop()const { return 300;}
};

class Boss : public monster {
private:
	int skillDamage;

	void init_stats();
public:
	Boss(string n);
	int dealDmg(int damage, Entity* target);
	int skill();
	inline int goldDrop()const { return 400;}
};
#endif // MONSTER_HPP