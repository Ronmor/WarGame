#pragma once

#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <iostream> // maybe delete later

#include "Soldier.hpp"

namespace WarGame
{

    struct ArmyInfo
    {
        std::map<Soldier *, std::pair<int, int>> _army;

        ArmyInfo();

        // methods
        void printArmyInfo();
        ArmyInfo &changeSoldierLocation(std::pair<int, int> &source, std::pair<int, int> &dest);

        std::map<Soldier *, std::pair<int, int>> &getArmy();
        bool hasSoldiers(uint team);
    };
} // namespace WarGame