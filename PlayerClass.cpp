#include "PlayerClass.hpp"

PlayerClass::~PlayerClass()
{
    for (Attack* i : this->atk_history) delete i;
}

void PlayerClass::process_atk(Attack* out_atk, Entity* target)
{
    target->takeDmg(this->dealDmg(out_atk->value, target), this);

    // TODO: possibly delegate this to another function which checks limit on vector
    atk_history.push_back(out_atk);
}

void PlayerClass::takeDmg(int atk_val, Entity* origin)
{
    // CombatMenu should check if health is below 1
    this->hp -= atk_val;
}

int PlayerClass::dealDmg(int atk_val, Entity* target)
{
    // for now, just return atk_val.
    // TODO: possibly add other factors, such as modifiers from equipment
    return atk_val;
}


Attack* Knight::attack_basic(Entity* target)
{
    Attack* atk = new Attack(5 + ((this->get_stats()->get_str() - 10)/2), 4, this);
    atk->loc += "Sword Slash";
    process_atk(atk, target);
    return atk;
}

Attack* Knight::attack_alt(Entity* target)
{
    // TODO: change value or add special effect or something
    Attack* atk = new Attack(5 + ((this->get_stats()->get_str() - 10)/2), 4, this);
    atk->loc += "Slap";
    process_atk(atk, target);
    return atk;
}

Attack* Knight::p_skill(Entity* target, int m_cost)
{
    Attack* atk = new Attack(15 + ((this->get_stats()->get_str() - 10) / 2), 4, this);
    atk->loc += "Laser Eye Attack";
    process_atk(atk, target);
    useMP(m_cost);
    return atk;
}


Attack* Archer::attack_basic(Entity* target)
{
    Attack* atk = new Attack(5 + ((this->get_stats()->get_dex() - 10)/2), 2, this);
    atk->loc += "Bow Shot";
    process_atk(atk, target);
    return atk;
}

Attack* Archer::attack_alt(Entity* target)
{
    // TODO: change value or add special effect or something
    Attack* atk = new Attack(5 + ((this->get_stats()->get_dex() - 10) / 2), 2, this);
    atk->loc += "Throw Rock";
    process_atk(atk, target);
    return atk;
}

Attack* Archer::p_skill(Entity* target, int m_cost)
{
    Attack* atk = new Attack(20 + ((this->get_stats()->get_dex() - 10) / 2), 12, this);
    atk->loc += "Under the Belt Kick";
    process_atk(atk, target);
    useMP(m_cost);
    return atk;
}


Attack* Mage::attack_basic(Entity* target)
{
    Attack* atk = new Attack(5 + ((this->get_stats()->get_brain() - 10)/2), 6, this);
    atk->loc += "Energy Bolt";
    process_atk(atk, target);
    return atk;
}

Attack* Mage::attack_alt(Entity* target)
{
    // TODO: change value or add special effect or something
    Attack* atk = new Attack(5 + ((this->get_stats()->get_brain() - 10) / 2), 6, this);
    atk->loc += "Zap";
    process_atk(atk, target);
    return atk;
}

Attack* Mage::p_skill(Entity* target, int m_cost)
{
    Attack* atk = new Attack(40 + ((this->get_stats()->get_dex() - 10) / 2), 30, this);
    atk->loc += "Trash Talk";
    process_atk(atk, target);
    useMP(m_cost);
    return atk;
}
