#include "ParamedicCommander.hpp"

using namespace WarGame;

ParamedicCommander::ParamedicCommander(uint team) : Paramedic(200, 0, team) {}

ParamedicCommander::~ParamedicCommander()
{
}

void ParamedicCommander::act(Soldier *target)
{
    target-> heal();
}
void ParamedicCommander::heal()
{
    this->_health = 200;
}

Soldier* ParamedicCommander::calcTarget(std::pair<int, int>& mycoords,map<Soldier*,std::pair<int, int>>& enemies,std::map<Soldier*,std::pair<int, int>>& allies)
{
    for(std::map<Soldier*,std::pair<int, int>>::iterator it = allies.begin() ; it != allies.end() ; it++)
    {
        if (dynamic_cast<Paramedic*>(it ->first))
        {
            it ->first ->act(it->first->T.sortByDistance(it->second,allies));
        }
    }
    return  T.sortByDistance(mycoords,allies);
}
