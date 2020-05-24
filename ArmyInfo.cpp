#include "ArmyInfo.hpp"


using std::sort;
using std::copy;
using std::map;
using std::pair;


using namespace WarGame;



ArmyInfo::ArmyInfo() : _army() {}

bool ArmyInfo::hasSoldiers(uint team)
{
    for(map<Soldier*,pair<int,int>>::iterator it = _army.begin(); it != _army.end(); it++)
    {
        if (it ->first ->getHealth() >  0) return true;
    }
    return false;
}
/*
void ArmyInfo::sortByHp()
{
    sort(_army.begin(),_army.end(),[](Soldier* sol1,Soldier* sol2)
    {
        return sol1 ->getHealth() > sol2 ->getHealth() ;
    });
}
*/


map<Soldier*,std::pair<int,int>>& ArmyInfo::getArmy()
{
    return _army;
}

