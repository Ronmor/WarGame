
#include <iostream>
#include "DemoGame.hpp"  

using namespace std;

int main() {
	WarGame::DemoGame demoGame;  // Initialize a game on a 8-by-8 board
	cout << "The winner is:\n " << demoGame.play() << endl;
    return 0;
}
