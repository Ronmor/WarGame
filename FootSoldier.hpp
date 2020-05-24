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
    FootSoldier(int life_points,int play_points,bool is_dist,uint player_number);
    ~FootSoldier();
    void makeMove2(std::pair<int, int> location);
    void makeMove();
  //  void makeMove(std::pair<int, int> location , Board::MoveDIR step_direction);
    //void attack(std::pair<int, int> location);
    //void myTargetToActUpon(std::vector<Soldier*>& armyToAct,std::pair<int, int> myCoordinate); // must have targets
    //double distance(std::pair<int, int>& myCoordinate,std::pair<int, int>& targets);
    virtual void act(Soldier* target);
    virtual void heal();
    virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&);
};

}