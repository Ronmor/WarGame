#include "FootCommander.hpp"
#include <iostream>

using namespace WarGame;
using std::vector;

FootCommander::FootCommander(uint team_num) : FootSoldier(150,20,team_num)  {}

FootCommander::~FootCommander()
{
    
}
void FootCommander::act(Soldier* target)
{
  //  std::cout << "footCommander->act()" << target ->getHealth() << std::endl;
    target ->updateHealth(-20);
  //  std::cout<<"health after FOOTCOMMANDER  shootss  " <<  target->getHealth() <<  std::endl;
}

void FootCommander::heal()
{
    this -> _health = 150;
}

Soldier* FootCommander::calcTarget(std::pair<int, int>& mycoors,std::map<Soldier*,std::pair<int, int>>& enemies,std::map<Soldier*,std::pair<int, int>>& allies)
{
   // std::cout<<"footCommander  " << std::endl;
    for(std::map<Soldier*,std::pair<int, int>>::iterator it = allies.begin() ; it != allies.end() ; it++)
    {
       // std::cout<< typeid(*it->first).name() << std::endl;
        if (dynamic_cast<FootSoldier*>(it ->first))
        {
        //    std::cout<<"footCommander  instructing to attack!" << std::endl;
         //   std::cout << "Soldier at (" << it->second.first << "," << it->second.second << ")" << "     is Ready" << std::endl;
            it ->first ->act(it->first->T.sortByDistance(it->second,enemies));
        }
    }
    return T.sortByDistance(mycoors,enemies);
}