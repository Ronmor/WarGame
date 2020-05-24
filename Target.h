#pragma once

#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <cmath>

// PREV INCLUDED ArmyInfo. we will se

/*

Soldier* getTarget(Soldier& soldierOf_A, std::vector<Soldier*>& army_B); // if failed to get target throw exception. or maybe dont do anything.


*/
using std::map;
//#include "Soldier.hpp"
namespace WarGame
{

    struct Target
    {
        //std::map<Soldier*,std::pair<int,int>> _soldiers_location;

        //Target();

        //void addSoldierLocation(Soldier* sold,std::pair<int,int> coords);

        //std::map<Soldier*,std::pair<int,int>>& getSoldiersLocations();
        template <typename T, typename E>
        T* sortByDistance(E& src_pair, map<T*,E>& _soldiers_location) const
        {
            double min_distance = 999999999.9;
            T* cand = nullptr;
            for (typename map<T*,E>::iterator it = _soldiers_location.begin(); it != _soldiers_location.end(); it++)
            {
                double temp_dist = boardDistance(src_pair, it->second);
                if (temp_dist < min_distance)
                {
                    cand = it->first;
                }
            }
            return cand;
        }
        template <typename E>
        double boardDistance(E& myCoordinate, E& targets) const
        {
            return pow(abs(myCoordinate.first - targets.first), 2) + pow(abs(myCoordinate.second - targets.second), 2);
        }
        template <typename T, typename E>
        T* strongestSoldier(std::map<T*,E> _soldiers_location)
        {
            int max_hp = 0;
            T* cand = nullptr;
            for (typename map<T*,E>::iterator it = _soldiers_location.begin(); it != _soldiers_location.end(); it++)
            {
                int temp_Hp = it->first->getHealth();
                if (max_hp < temp_Hp)
                {
                    cand = it->first;
                }
            }
            return cand;
        }
    };

} // namespace WarGame