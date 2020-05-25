/**
 * Header file for the board of the war game.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */
#pragma once



#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Soldier.hpp"
#include "ArmyInfo.hpp"


namespace WarGame {

class Board {
  private:
    std::vector<std::vector<Soldier*>> board;
    ArmyInfo army_A;
    ArmyInfo army_B;

    // my methods should be private. if needed , give friend privleges.
    

  public:
    enum MoveDIR { Up, Down, Right, Left };
    
    uint _rows;
    uint _cols;
    Board(uint numRows, uint numCols);
     

    // operator for putting soldiers on the game-board during initialization.
    Soldier*& operator[](std::pair<int,int> location);
    
    // operator for reading which soldiers are on the game-board.
    Soldier* operator[](std::pair<int,int> location) const;
    
    // The function "move" tries to move the soldier of player "player"
    //     from the "source" location to the "target" location,
    //     and activates the special ability of the soldier.
    // If the move is illegal, it throws "std::invalid_argument". 
    // Illegal moves include:
    //  * There is no soldier in the source location (i.e., the soldier pointer is null);
    //  * The soldier in the source location belongs to the other player.
    //  * There is already another soldier (of this or the other player) in the target location.
    // IMPLEMENTATION HINT: Do not write "if" conditions that depend on the type of soldier!
    // Your code should be generic. All handling of different types of soldiers 
    //      must be handled by polymorphism.
    void move(uint player_number, std::pair<int,int> source, MoveDIR direction);

    // returns true iff the board contains one or more soldiers of the given player.
    bool has_soldiers(uint player_number);
    bool movementValidator(std::pair<int, int>& toValidate);
    std::pair<int, int> permissionToChangeLocation(std::pair<int, int>& source, MoveDIR direction);

    std::vector<std::vector<Soldier*>>& getBoard();

    bool isEmptySpace(std::pair<int,int> board_cell);
    bool isEmptySpace(std::pair<int,int> board_cell) const;
    ArmyInfo& getArmyInfo(uint team);

    Board& updateBoard();
    std::pair<int, int> soldierTargetToActUpon(std::pair<int, int> actingSoldier);

    ~Board();
  // my additions





};

}