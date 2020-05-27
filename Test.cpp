#include "doctest.h"
#include <iostream>
#include <stdexcept>
using namespace std;

#include "Board.hpp"

#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

using namespace WarGame;

TEST_CASE("Foot soldiers and Foot Commanders Game")
{
    Board board(8, 8);
    CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{0, 5}] = new FootSoldier(1);
    board[{0, 0}] = new FootSoldier(1);
    board[{0, 2}] = new FootSoldier(1);
    board[{0, 4}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{7, 1}] = new FootSoldier(2);
    board[{7, 3}] = new FootCommander(2);
    board[{7, 5}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));
    CHECK_NOTHROW(board.move(1, {0, 1}, Board::MoveDIR::Up)); // FootSoldier of player 1 moves forward and attacks.
    CHECK(board.has_soldiers(2));
    CHECK_THROWS(board.move(1, {0, 1}, Board::MoveDIR::Up));    // no soldier in source
    CHECK_THROWS(board.move(2, {1, 1}, Board::MoveDIR::Up));    // belong to other player
    CHECK_THROWS(board.move(1, {0, 3}, Board::MoveDIR::Right)); // there is someone else at dest
    CHECK_THROWS(board.move(1, {0, 0}, Board::MoveDIR::Down));
    CHECK_THROWS(board.move(1, {0, 0}, Board::MoveDIR::Left));
    CHECK_NOTHROW(board.move(2, {7, 1}, Board::MoveDIR::Right));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(2, {7, 1}, Board::MoveDIR::Up)); // no soldier in source
    CHECK_THROWS(board.move(1, {7, 2}, Board::MoveDIR::Up)); // belong to other player
    CHECK_NOTHROW(board.move(1, {0, 3}, Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK_THROWS(board.move(1, {0, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {1, 3}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(2, {7, 3}, Board::MoveDIR::Down));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(2, {7, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {6, 3}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(1, {0, 5}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {0, 5}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {1, 5}, Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK_NOTHROW(board.move(1, {1, 3}, Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK_NOTHROW(board.move(1, {2, 3}, Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK_NOTHROW(board.move(1, {3, 3}, Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK_NOTHROW(board.move(2, {7, 2}, Board::MoveDIR::Left));
    CHECK(board.has_soldiers(1));
    CHECK_NOTHROW(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK(!board.has_soldiers(2));
    // illegal moves
    CHECK_THROWS(board.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
}

TEST_CASE("Foot soldiers and Snipers , SniperCommander and Paramedic")
{
    Board board(8, 8);
    CHECK(!board.has_soldiers(1));
    board[{0, 1}] = new SniperCommander(1);
    board[{0, 3}] = new Sniper(1);
    board[{0, 5}] = new Sniper(1);
    board[{0, 0}] = new Sniper(1);
    board[{0, 2}] = new Sniper(1);
    board[{0, 4}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));
    board[{7, 1}] = new Paramedic(2);
    board[{7, 2}] = new SniperCommander(2);
    board[{7, 0}] = new Sniper(2);
    CHECK(board.has_soldiers(2));

    CHECK_NOTHROW(board.move(2, {7, 2}, Board::MoveDIR::Right)); // FootSoldier of player 1 moves forward and attacks.
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1, {7, 3}, Board::MoveDIR::Up));    // belong to other player
    CHECK_THROWS(board.move(2, {7, 2}, Board::MoveDIR::Up));    // no longer there
    CHECK_THROWS(board.move(1, {0, 2}, Board::MoveDIR::Right)); // there is someone else at dest
    CHECK_THROWS(board.move(1, {0, 4}, Board::MoveDIR::Up)); // died last round
    CHECK_THROWS(board.move(1, {0, 7}, Board::MoveDIR::Up)); // NULL
    CHECK_NOTHROW(board.move(2, {7, 1}, Board::MoveDIR::Right));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(2, {7, 1}, Board::MoveDIR::Up)); // no soldier in source
    CHECK_THROWS(board.move(1, {7, 2}, Board::MoveDIR::Up)); // belong to other player
    CHECK_NOTHROW(board.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK(board.has_soldiers(2));
    CHECK_NOTHROW(board.move(1, {0, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {1, 3}, Board::MoveDIR::Up));
    CHECK_NOTHROW(board.move(2, {7, 3}, Board::MoveDIR::Down));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(2, {7, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {3, 3}, Board::MoveDIR::Up));

    CHECK_THROWS(board.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {0, 1}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(1, {4, 3}, Board::MoveDIR::Up));
    // If no player won, return "tie":
}
