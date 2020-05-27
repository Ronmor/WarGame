#include "SniperCommander.hpp"

using namespace WarGame;

SniperCommander::SniperCommander(uint team) : Sniper(120, 100, team) {}

SniperCommander::~SniperCommander()
{
}

void SniperCommander::act(Soldier *target)
{
    target->updateHealth(-100);
}
void SniperCommander::heal()
{
    this->_health = 120;
}
Soldier* SniperCommander::calcTarget(std::pair<int, int>& mycoords,std::map<Soldier*,std::pair<int, int>>& enemies,std::map<Soldier*,std::pair<int, int>>& allies)
{
    for(std::map<Soldier*,std::pair<int, int>>::iterator it = allies.begin() ; it != allies.end() ; it++)
    {
        if (dynamic_cast<Sniper*>(it ->first))
        {
            it ->first ->act(it->first->T.strongestSoldier(enemies));
        }
    }
    return T.strongestSoldier(enemies);
}