#include "ArmyInfo.hpp"

using std::copy;
using std::map;
using std::pair;
using std::sort;

using namespace WarGame;

ArmyInfo::ArmyInfo() : _army() {}

bool ArmyInfo::hasSoldiers(uint team)
{
    for (map<Soldier *, pair<int, int>>::iterator it = _army.begin(); it != _army.end(); it++)
    {
        if (it->first->getHealth() > 0)
            return true;
    }
    return false;
}

void ArmyInfo::printArmyInfo()
{
    if (!_army.empty())
    {
        for (map<Soldier *, pair<int, int>>::iterator it = _army.begin(); it != _army.end(); it++)
        {
            if (it->first->isAlive())
            {
                std::cout << "located at (" << it->second.first << "," << it->second.second << ")"
                          << "     | Health Points  =  " << it->first->getHealth() << "|"
                          << std::endl;
            }
        }
    }
}
ArmyInfo &ArmyInfo::changeSoldierLocation(std::pair<int, int> &source, std::pair<int, int> &dest)
{
    for (map<Soldier *, pair<int, int>>::iterator it = _army.begin(); it != _army.end(); it++)
    {
        if (it->second.first == source.first && it->second.second == source.second)
        {
            //  std::cout << "located at (" << it->second.first << "," << it->second.second << ")"
            //           << "     | Health Points  =  " << it->first->getHealth() << "|"
            //           << std::endl;
           // std::cout << "it->second = " << it->second.first << "," << it->second.second << std::endl;
            it->second = dest;
           // std::cout << "it->second = " << it->second.first << "," << it->second.second << std::endl;
            return *this;
        }
    }
    return *this;
}

map<Soldier *, std::pair<int, int>> &ArmyInfo::getArmy()
{
    return _army;
}
