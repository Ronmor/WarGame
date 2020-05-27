
/*
this Abstract class defines :
all instances protected fields are : init_health , play_score(attack or heal)


constructor + may need a default constructor as well 

operator = 

d'tor must be virtual to avoid memory leaks

inAddition, pure virtual method is requierd, and method such as heal for paramedic, will work on (const Soldier&)

A cpy c'tor is essential cause of pointers using


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
    int _score_points; // since there are differences between attack(foot soldiers and snipers), to defence(paramedics). Also does not violate O principle of solid
    uint _team;
public:
    Target T;
    
    
    Soldier(int life_points,int play_points,uint team_num);
    Soldier(uint team_num);
    virtual ~Soldier();
    Soldier(const Soldier*& other);
    int getHealth() const;
    Soldier& updateHealth(int);
    uint getTeamNumber();
    Soldier& operator=(const Soldier&);   
    bool isAlive() const;

    virtual void act(Soldier* target) = 0;
    virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&,std::map<Soldier*,std::pair<int, int>>&) = 0;
    virtual void heal() = 0;
};


}