
/*
this Abstract class defines :
all instances protected fields are : init_health , play_score(attack or heal)


constructor + may need a default constructor as well 

operator = 

d'tor must be virtual to avoid memory leaks

inAddition, pure virtual method is requierd, and method such as heal for paramedic, will work on (const Soldier&)

*/
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Target.h"


namespace WarGame{

class Soldier
{
protected:
    int _health;
    int _score_points;
    bool _isCalculatingTargetbydistance; // since there are differences between attack(foot soldiers and snipers), to defence(paramedics). Also does not violate O principle of solid
    uint _team;
    Target T;

public:
    Soldier(int life_points,int play_points,bool is_distanceFactor,uint team_num);
    Soldier(uint team_num);
    virtual ~Soldier();
    int getHealth() const;
    Soldier& updateHealth(int);
    uint getTeamNumber();
    Soldier& setTeam(uint team_num);
    bool isAttackingSoldier() const;
    Soldier& operator=(const Soldier&);   
    // opposition for everyone but paramedics. 
    
    /*
    
    */
    //virtual void myTargetToActUpon(std::vector<Soldier*>& armyToAct,std::pair<int, int> myCoordinate) = 0 ;
    virtual void act(Soldier* target) = 0;
    virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&) = 0;
    virtual void heal() = 0;
};


}