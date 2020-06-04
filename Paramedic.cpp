#include "Paramedic.hpp"


using namespace WarGame;

Paramedic::Paramedic(uint team) : Soldier(100,0,team) {}

Paramedic::Paramedic(int life_points,int play_points,uint team_num) : Soldier(life_points,play_points,team_num) {}

Paramedic::~Paramedic(){}

void Paramedic::act(Soldier* target)
{
    target -> heal();
}
void Paramedic::heal()
{
    this->_health = 100;
}
Soldier* Paramedic::calcTarget(std::pair<int, int>& mycoords,std::map<Soldier*,std::pair<int, int>>& enemies,std::map<Soldier*,std::pair<int, int>>& allies){
    Soldier* actUpon =  T.sortByDistance(mycoords,allies);
    if(actUpon == NULL || !actUpon->isAlive()) 
    {std::cout << "actUpon is NULL  !!"  << std::endl;
    // in our implementation , we were ready to a real time competitive game, so as soon as a soldier's HP hits zero, his out.
    // unfortunatly, test was planned differently, where the removal of a dead soldier is not happening.
    // hence' current solution passes Null to act(Soldier*) fuction.
    // the easy way out is to initiate a self attack, but dont acctually decrease HP to itself.
    Soldier* paramedic_ptr = this;
    return paramedic_ptr;
    }
    act(actUpon);
    return actUpon;
}