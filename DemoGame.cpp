/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"

#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

namespace WarGame
{

	DemoGame::DemoGame(int rows, int cols) : board(rows, cols) {}
	Board &DemoGame::getBoard() { return board; }
	DemoGame::DemoGame() : board(8, 8)
	{
		// Add soldiers for player 1:
		//	assert(!board.has_soldiers(1));
		board[{0, 1}] = new FootSoldier(1);
		board[{0, 3}] = new FootCommander(1);
		board[{0, 0}] = new FootSoldier(1);
		board[{0, 0}] = new FootSoldier(1);
		board[{0, 2}] = new FootSoldier(1);
		board[{0, 4}] = new FootSoldier(1);
		//	assert(board.has_soldiers(1));

		// Add soldiers for player 2:
		//	assert(!board.has_soldiers(2));
		board[{7, 1}] = new FootSoldier(2);
		board[{7, 3}] = new FootCommander(2);
		board[{7, 5}] = new FootSoldier(2);
		//	assert(board.has_soldiers(2));

		// In your game, you can put more soldier types, such as the sniper and the paramedic types.
	}

	DemoGame::~DemoGame()
	{
		for (int iRow = 0; iRow < board._rows; ++iRow)
		{
			for (int iCol = 0; iCol < board._cols; ++iCol)
			{
				Soldier *soldier = board[{iRow, iCol}];
				if (soldier)
					delete soldier;
			}
		}
	}

	uint DemoGame::play()
	{

		board.move(1, {0, 1}, Board::MoveDIR::Up); // FootSoldier of player 1 moves forward and attacks.
		if (!board.has_soldiers(2))
			return 1;
		board.move(2, {7, 1}, Board::MoveDIR::Right); // FootSoldier of player 2 moves forward and attacks.
		if (!board.has_soldiers(1))
			return 2;
		board.move(1, {0, 3}, Board::MoveDIR::Up); // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
		if (!board.has_soldiers(2))
			return 1;
		board.move(2, {7, 3}, Board::MoveDIR::Down); // FootCommander of player 2 moves left, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1))
			return 2;
		board.move(2, {7, 2}, Board::MoveDIR::Left); // FootCommander of player 2 moves left, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1))
			return 2;
		//board.move(1, {0, 0}, Board::MoveDIR::Right); // FootCommander of player 2 moves left, and all soldiers of player 2 attack.
		if (!board.has_soldiers(1))
			return 2;
		/*
			/// Write more moves here..
	
			*/

		board.move(1, {1, 3}, Board::MoveDIR::Up); // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
		if (!board.has_soldiers(2))
			return 1;
		board.move(1, {2, 3}, Board::MoveDIR::Up); // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
		if (!board.has_soldiers(2))
			return 1;
		board.move(1, {3, 3}, Board::MoveDIR::Up); // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
		if (!board.has_soldiers(2))
			return 1;
		//board.printBoardVectors();
		board.move(1, {4, 3}, Board::MoveDIR::Up); // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
		if (!board.has_soldiers(2))
			return 1;
		// If no player won, return "tie":
		return 0;
	}
} // namespace WarGame
