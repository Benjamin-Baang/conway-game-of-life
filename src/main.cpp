#include <iostream>
#include <unistd.h> // For sleep()

#include "gameOfLife.hpp"

using namespace std;

/*
Conway's Game of Life

A cellular automaton played on a 2D grid. Each cell follows 4 rules:
    1. Any live cell with less than 2 neighbors die.
    2. Any live cell with more than 3 neighbors die.
    3. Any live cell with 2 or 3 neighbors live.
    4. Any dead cell with exactly 3 neighbors are born (become live).
*/

int main()
{
    GameOfLife state;
    int width = 50;
    int height = 20;
    // Creates a random state, taking a width and height.
    // The user can also use their own state by using the set_board_state method
    state.random_state(width, height);

    // Infinite loop
    while(1)
    {
        cout << state << endl;
        // This is needed because it's too fast to see otherwise
        sleep(1);
        // Get next state according to the set rules
        state.next_board_state();
    }
}
