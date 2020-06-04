#include <iostream>
#include "Board.hpp"

using namespace WarGame;

using std::cerr;
using std::cout;
using std::endl;
using std::invalid_argument;
using std::pair;
using std::vector;

Board::Board(uint numRows, uint numCols) : board(numRows, vector<Soldier *>(numCols, nullptr)), army_A(), army_B(),
                                           _rows(numRows), _cols(numCols)
{
}

// operator for putting soldiers on the game-board during initialization.
Soldier *&Board::operator[](pair<int, int> location)
/* 
INIT MUST BE FOLLOWED BY A BOARD UPDATE. ONCE A NEW SOLDIER HAS BEEN SET, READ IT'S LOCATION WITH THE OTHER OPERATOR[].
FIND OUT SOLDIERS TEAM, AND UPDATE MAP(TARGET).
ALSO UPDATE THE ARMYINFO, MAKING TWO VECTORS , EACH FOR ONE ARMY.

*/
{
    return board.at(location.first).at(location.second);
}

// operator for reading which soldiers are on the game-board.
Soldier *Board::operator[](pair<int, int> location) const
{
    // if outOfBounds
    if (this->_rows <= location.first || this->_cols <= location.second)
        throw invalid_argument("Out of bound");
    try
    {
        const bool empty_space = isEmptySpace(location);
        if (!empty_space)
        {
            return board.at(location.first).at(location.second);
        }
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << endl;
    }
    return nullptr;
}
bool Board::isEmptySpace(pair<int, int> board_cell) const
{
    return board[board_cell.first][board_cell.second] == NULL;
}
bool Board::isEmptySpace(pair<int, int> board_cell)
{
    return board[board_cell.first][board_cell.second] == NULL;
}
pair<int, int> Board::permissionToChangeLocation(pair<int, int> &source, MoveDIR direction)
{
    switch (direction)
    {
    case MoveDIR::Up:
        return std::make_pair(source.first + 1, source.second);
        break;
    case MoveDIR::Down:
        return std::make_pair(source.first - 1, source.second);
        break;
    case MoveDIR::Left:
        return std::make_pair(source.first, source.second - 1);
        break;
    case MoveDIR::Right:
        return std::make_pair(source.first, source.second + 1);
        break;
    default:
        break;
    }
}
bool Board::movementValidator(pair<int, int> &toValidate)
{

    if (toValidate.first < 0 || toValidate.first >= _rows)
        throw invalid_argument("out of bounds in rows");
    if (toValidate.second < 0 || toValidate.second >= _cols)
        throw invalid_argument("out of bounds in cols");
    try
    {
    if (board[toValidate.first][toValidate.second] != NULL)
        return false;        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return true;
}

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

void Board::move(uint player_number, pair<int, int> source, MoveDIR direction)
{
    
    readBoardState();
    //cout << source.first << "," << source.second << "###                          ######" << endl;
    if (isEmptySpace(source))
        throw invalid_argument("There is no soldier in the source location");
    if (board[source.first][source.second]->getTeamNumber() != player_number)
        throw invalid_argument("The soldier in the source location belongs to the other player.");
    pair<int, int> required_dest = permissionToChangeLocation(source, direction);
    bool is_legal_move = movementValidator(required_dest);
    //Soldier *actUpon = nullptr; // if not on commet , later is calling copyConstructor.
    if (!is_legal_move)
        throw invalid_argument("There is already another soldier (of this or the other player) in the target location.");
    bool is_team_A = player_number == 1;
    uint allies = is_team_A ? 1 : 2;
    uint enemies = is_team_A ? 2 : 1;
    try
    {
        Soldier *p_soldi = board[source.first][source.second]; // copy c'tor
        board[required_dest.first][required_dest.second];
        board[required_dest.first][required_dest.second] = p_soldi;
        movePiece(allies, source, required_dest);
        Soldier *actUpon = board[source.first][source.second]->calcTarget(required_dest, getArmyInfo(enemies).getArmy(), getArmyInfo(allies).getArmy());
        if (board.at(source.first).at(source.second) != NULL)
        {
            board[source.first][source.second] = NULL;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    cout << endl;
    //printBoardVectors();
    //cout << "End of Move" << endl;
}

// returns true iff the board contains one or more soldiers of the given player.
bool Board::has_soldiers(uint player_number)
{
    readBoardState();
    bool still_has_soldiers = !getArmyInfo(player_number).getArmy().empty();
    if (still_has_soldiers)
    {
        return true;
    }
    else
     //   cout << "amount of soldiers left = " << getArmyInfo(player_number).getArmy().size() << endl;
    return still_has_soldiers;
}

vector<vector<Soldier *>> &Board::getBoard()
{
    return board;
}
ArmyInfo &Board::getArmyInfo(uint team)
{
    if (team == 1)
    {
        return army_A;
    }
    return army_B;
}

Board &Board::readBoardState()
{
    for (size_t i = 0; i < _rows; i++)
    {
        for (size_t j = 0; j < _cols; j++)
        {
            if (board.at(i).at(j) != NULL)
            {
                if (board[i][j]->isAlive())
                {
                    getArmyInfo(board[i][j]->getTeamNumber()).getArmy().insert(std::make_pair(board[i][j], std::make_pair(i, j)));
                }
                else
                {
                    getArmyInfo(board[i][j]->getTeamNumber()).getArmy().erase(board[i][j]);
                }
            }
        }
    }
    return *this;
}
Board &Board::updateBoard()
{

    return *this;
}
Board &Board::movePiece(uint team_number, std::pair<int, int> source, std::pair<int, int> dest)
{
    getArmyInfo(team_number).changeSoldierLocation(source, dest);
    return *this;
}

void Board::printFullBoardState()
{
    cout << "######################################################################################" << endl;
    cout << "###### TEAM        A : " << endl;
    army_A.printArmyInfo();
    cout << endl;
    cout << endl;
    cout << "###### TEAM        B : " << endl;
    army_B.printArmyInfo();
    cout << "End of Turn" << endl;
}

Board::~Board()
{
    board.clear();
}

void Board::printBoardVectors()  // delete when code is complete
{
    cout << "board.size = " << board.size() << "            "
         << "board.at(0).size = " << board.at(0).size() << endl;
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = 0; j < board.at(0).size(); j++)
        {
            if (board.at(i).at(j) != NULL)
            {
                std::cout << "located at (" << i << "," << j << ")"
                          << "     | Health Points  =  " << board[i][j]->getHealth() << "|"
                          << std::endl;
            }
        }
    }
}
