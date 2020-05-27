#pragma once

#include "Soldier.hpp"

namespace WarGame{

class Paramedic : public WarGame::Soldier
{
private:
    /* data */
public:
    Paramedic(uint team);
    Paramedic(int life_points,int play_points,uint team_num);
    ~Paramedic();

    virtual void act(Soldier* target);
    virtual void heal();
    virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&,std::map<Soldier*,std::pair<int, int>>&);
};




}