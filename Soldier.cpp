#include "Soldier.hpp"

using namespace WarGame;

Soldier::Soldier(int life_points, int play_points, uint team_num)
    : _health(life_points), _score_points(play_points), _team(team_num)
{
}
Soldier::Soldier(uint team_num) : _team(team_num) {}

Soldier::~Soldier() {}

Soldier::Soldier(const Soldier *&other)
{
    _health = other->_health;
    _score_points = other->_score_points;
    _team = other->_team;
}

int Soldier::getHealth() const
{
    return _health;
}
bool Soldier::isAlive() const
{
    return this->getHealth() > 0;
}

uint Soldier::getTeamNumber()
{
    return _team;
}

Soldier &Soldier::updateHealth(int value)
{
    _health += value;
    return *this;
}

Soldier &Soldier::operator=(const Soldier &other)
{
    this->_health = other._health;
    this->_score_points = other._score_points;
    return *this;
}
