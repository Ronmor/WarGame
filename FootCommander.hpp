#pragma once

#include <vector>
#include <iterator>
#include <algorithm>
#include "FootSoldier.hpp"

namespace WarGame{

class FootCommander : public WarGame::FootSoldier
{
    
protected:
    
public:
    FootCommander(uint team_num);
    ~FootCommander();
    //void instructAllToAttack(std::vector<WarGame::Soldier*>);
    virtual void act(Soldier* target) override;
    virtual void heal() override;
    virtual Soldier* calcTarget(std::pair<int, int>&,std::map<Soldier*,std::pair<int, int>>&) override;
};


}