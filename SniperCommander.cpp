#include "SniperCommander.hpp"

using namespace WarGame;

SniperCommander::SniperCommander(uint team) : Sniper(120, 100, true, team) {}

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
Soldier* SniperCommander::calcTarget(std::pair<int, int>& mycoords,std::map<Soldier*,std::pair<int, int>>& enemies)
{
    return T.strongestSoldier(enemies);
}