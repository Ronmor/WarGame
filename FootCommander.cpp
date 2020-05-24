#include "FootCommander.hpp"
#include <iostream>

using namespace WarGame;
using std::vector;

FootCommander::FootCommander(uint team_num) : FootSoldier(150,20,true,team_num)  {}

FootCommander::~FootCommander()
{
    
}
/*
void FootCommander::instructAllToAttack(vector<Soldier*>& footSoldiers)
{
    for (vector<Soldier*>::iterator it = footSoldiers.begin() ; it != footSoldiers.end() ; it++)
    {
        if(dynamic_cast<FootSoldier*>(it))
        {

        }
    }
    
    //std::for_each(_footSoldiers.begin(),_footSoldiers.end(),engage);
}
*/
void FootCommander::act(Soldier* target)
{
    //std::cout << "footCommander->act()" << std::endl;
    target ->updateHealth(-20);
}

void FootCommander::heal()
{
    this -> _health = 150;
}

Soldier* FootCommander::calcTarget(std::pair<int, int>& mycoors,std::map<Soldier*,std::pair<int, int>>& enemies)
{
    return T.sortByDistance(mycoors,enemies);
}