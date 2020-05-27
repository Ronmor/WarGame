#include "Sniper.hpp"

using namespace WarGame;

Sniper::Sniper(uint team) : Soldier(100,50,team) {}

Sniper::Sniper(int life_points,int play_points,uint team_num) : Soldier(life_points,play_points,team_num) {}

Sniper::~Sniper()
{}

void Sniper::act(Soldier* target)
{
    target -> updateHealth(-50);
}

void Sniper::heal() {
    this->_health = 100;
}

Soldier* Sniper::calcTarget(std::pair<int, int>& myCoords,std::map<Soldier*,std::pair<int, int>>& enemies,std::map<Soldier*,std::pair<int, int>>& allies)
{
    Soldier* actUpon = T.strongestSoldier(enemies);
    act(actUpon);
    return actUpon;
}