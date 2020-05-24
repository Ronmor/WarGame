#include "Sniper.hpp"

using namespace WarGame;

Sniper::Sniper(uint team) : Soldier(100,50,true,team) {}

Sniper::Sniper(int life_points,int play_points,bool is_attacking,uint team_num) : Soldier(life_points,play_points,is_attacking,team_num) {}

Sniper::~Sniper()
{}

void Sniper::act(Soldier* target)
{
    target -> updateHealth(-50);
}

void Sniper::heal() {
    this->_health = 100;
}

Soldier* Sniper::calcTarget(std::pair<int, int>& myCoords,std::map<Soldier*,std::pair<int, int>>& enemies)
{
    return T.strongestSoldier(enemies);
}