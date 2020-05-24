#include "Paramedic.hpp"


using namespace WarGame;

Paramedic::Paramedic(uint team) : Soldier(100,0,false,team) {}

Paramedic::Paramedic(int life_points,int play_points,bool is_attacking,uint team_num) : Soldier(life_points,play_points,is_attacking,team_num) {}

Paramedic::~Paramedic(){}

void Paramedic::act(Soldier* target)
{
    target -> heal();
}
void Paramedic::heal()
{
    this->_health = 100;
}
Soldier* Paramedic::calcTarget(std::pair<int, int>& mycoords,std::map<Soldier*,std::pair<int, int>>& allies){
    return T.sortByDistance(mycoords,allies);
}