#pragma once
/*
a Map<Soldier*,pair<int,int>> sold_ptr,location

a vector of soldiers and a sorting method by HealthPoints


*/

#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <cmath>

#include "Soldier.hpp"
#include "Comperator_HP.hpp"


namespace WarGame{

struct ArmyInfo
{
std::map<Soldier*,std::pair<int,int>> _army;

ArmyInfo();

    // methods

//void sortByHp();


std::map<Soldier*,std::pair<int,int>>& getArmy();
bool hasSoldiers(uint team);


};
}