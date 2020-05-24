#include "ParamedicCommander.hpp"

using namespace WarGame;

ParamedicCommander::ParamedicCommander(uint team) : Paramedic(200, 0, false, team) {}

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

Soldier* ParamedicCommander::calcTarget(std::pair<int, int>& mycoords,map<Soldier*,std::pair<int, int>>& allies)
{
    return  T.sortByDistance(mycoords,allies);
}
