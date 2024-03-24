#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class GameOfLife
{
    private:
        vector<vector<int>> game_state;

    public:
        /**
         * \brief Initial board state.
         * 
         * All cells are initialized as dead cells.
         * 
         * \param width An int parameter specifying width
         * \param height An int parameter specifying height
        **/
        void dead_state(int width, int height);

        /**
         * \brief Random board state.
         * 
         * All cells are randomly determined as dead or alive.
         * 
         * \param width An int parameter specifying width
         * \param height An int parameter specifying height
        */
        void random_state(int width, int height);

        /**
         * \brief Determines next board state.
         * 
         * All cells will live or die according to specific rules.
         * For more information, look up Conway's Game of Life.
        */
        void next_board_state();

        /**
         * \brief Sets board state.
         * 
         * Takes a user's desired board state and assigns it to this class's board state.
         * 
         * \param state A 2D vector of integers
        */
        void set_board_state(vector<vector<int>> state);

        /**
         * \brief Gets the class's board state.
         * 
         * \return 2D vector of integers
        */
        vector<vector<int>> get_board_state();

        /**
         * \brief Overrides the output operator to output this class.
        */
        friend ostream& operator<< (ostream& os, const GameOfLife& state);
};