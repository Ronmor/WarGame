#pragma once

#include "Soldier.hpp"

namespace WarGame{

class Sniper : public WarGame::Soldier
{
private:
    /* data */
public:
    Sniper(uint team);
    Sniper(int life_points,int play_points,uint team_num);
    ~Sniper();

    virtual void act(Soldier* target);
    virtual void heal();
    virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&,std::map<Soldier*,std::pair<int, int>>&);
};




}