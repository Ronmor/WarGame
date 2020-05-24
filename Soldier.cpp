#include "Soldier.hpp"

using namespace WarGame;


Soldier::Soldier(int life_points,int play_points,bool is_distanceFactor,uint team_num)
: _health(life_points) , _score_points(play_points) , _isCalculatingTargetbydistance(is_distanceFactor) , _team(team_num) 
{
    
}
Soldier::Soldier(uint team_num) : _team(team_num) {}

Soldier::~Soldier() {}

int Soldier::getHealth() const {
    return _health;
}
bool Soldier::isAttackingSoldier() const {
    return _isCalculatingTargetbydistance;
}
uint Soldier::getTeamNumber()
{
    return _team;
}

Soldier& Soldier::setTeam(uint team_num)
{
    _team = team_num;
    return *this;
}


Soldier& Soldier::updateHealth(int value)
{
    _health += value;
    return *this;
}


Soldier& Soldier::operator=(const Soldier& other)
{
    this->_health = other._health;
    this->_score_points = other._score_points;
    this->_isCalculatingTargetbydistance = other._isCalculatingTargetbydistance;
    return *this;
}

