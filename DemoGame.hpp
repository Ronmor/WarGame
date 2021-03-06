#pragma once
/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "Board.hpp"
using namespace WarGame;
	
	class DemoGame {
	 private:
		Board board;
	 public:
	 	DemoGame(int rows,int cols);
		Board& getBoard();
 		/**
		 * The constructor initilizes the board and places the soldiers.
		 */
		DemoGame();
		~DemoGame();
		/**
		 * This function runs a sample play of the game and returns the winner (1 or 2, or 0 in case of tie).
		 */
		uint play(); 
	};

