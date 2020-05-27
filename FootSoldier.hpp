#pragma once

#include "Soldier.hpp"
#include <cmath>

namespace WarGame{

class FootSoldier : public WarGame::Soldier
{
protected:
     //closest enemy
public:
    FootSoldier(uint team_num);
    FootSoldier(int life_points,int play_points,uint player_number);
    ~FootSoldier();
    void makeMove2(std::pair<int, int> location);
    void makeMove();
    virtual void act(Soldier* target);
    virtual void heal();
    virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&,std::map<Soldier*,std::pair<int, int>>&);
};

}