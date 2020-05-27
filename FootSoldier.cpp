#include "FootSoldier.hpp"

#include <iostream>
/*
FootSoldier - רגלי - יכול ללכת משבצת אחת לכל כיוון. יורה על החייל של האויב שנמצא הכי קרוב אליו (אם יש כמה - הוא יורה על אחד מהם שרירותית).

FootSoldier: initial health points=100, damage per activity=10
*/

using namespace WarGame;
using std::abs;
using std::pow;

FootSoldier::FootSoldier(uint team_num) : Soldier(100, 10, team_num)
{
}

FootSoldier::FootSoldier(int life_points, int play_points, uint player_number) : Soldier(life_points, play_points, player_number)
{
}

FootSoldier::~FootSoldier()
{

}

void FootSoldier::act(Soldier *target)
{
    if(target) target->updateHealth(-10);
}
void FootSoldier::heal()
{
    this->_health = 100;
}
Soldier* FootSoldier::calcTarget(std::pair<int, int>& myCoords,std::map<Soldier*,std::pair<int, int>>& enemies,std::map<Soldier*,std::pair<int, int>>& allies)
{
    Soldier* actUpon = T.sortByDistance(myCoords,enemies);
    act(actUpon); 
    return actUpon;
}