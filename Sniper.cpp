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
    if(actUpon == NULL || !actUpon->isAlive()) 
    {std::cout << "actUpon is NULL  !!"  << std::endl;
    // in our implementation , we were ready to a real time competitive game, so as soon as a soldier's HP hits zero, his out.
    // unfortunatly, test was planned differently, where the removal of a dead soldier is not happening.
    // hence' current solution passes Null to act(Soldier*) fuction.
    // the easy way out is to initiate a self attack, but dont acctually decrease HP to itself.
    Soldier* sniper_ptr = this;
    return sniper_ptr;
    }
    act(actUpon);
    return actUpon;
}