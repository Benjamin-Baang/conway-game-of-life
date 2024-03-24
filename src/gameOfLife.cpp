#include "gameOfLife.hpp"

void GameOfLife::dead_state(int width, int height)
{
    this->game_state.resize(height, vector<int>(width, 0));
}

void GameOfLife::random_state(int width, int height)
{
    srand(time(0));
    dead_state(width, height);
    for(int i=0; i<this->game_state.size(); i++)
    {
        for(int j=0; j<this->game_state[0].size(); j++)
        {
            this->game_state[i][j]=rand()%2;
        }
    }
}

void GameOfLife::next_board_state()
{
    vector<vector<int>> temp_state;
    temp_state = this->game_state;

    for(int i=0; i<this->game_state.size(); i++)
    {
        for(int j=0; j<this->game_state[0].size(); j++)
        {
            // Top Left Corner
            if(i==0 && j==0)
            {
                // Cell is alive
                if(this->game_state[i][j])
                {
                    int sum=this->game_state[i][j+1]+this->game_state[i+1][j+1]+this->game_state[i+1][j];
                    if(sum<=1)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(this->game_state[i][j+1] && this->game_state[i+1][j+1] && this->game_state[i+1][j])
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
            // Top Right Corner
            else if(i==0 && j==this->game_state[0].size()-1)
            {
                // Cell is alive
                if(this->game_state[i][j])
                {
                    int sum=this->game_state[i+1][j]+this->game_state[i+1][j-1]+this->game_state[i][j-1];
                    if(sum<=1)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(this->game_state[i+1][j] && this->game_state[i+1][j-1] && this->game_state[i][j-1])
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
            // Bottom Left Corner
            else if(i==this->game_state.size()-1 && j==0)
            {
                // Cell is alive
                if(this->game_state[i][j])
                {
                    int sum=this->game_state[i-1][j]+this->game_state[i-1][j+1]+this->game_state[i][j+1];
                    if(sum<=1)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(this->game_state[i-1][j] && this->game_state[i-1][j+1] && this->game_state[i][j+1])
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
            // Bottom Right Corner
            else if(i==this->game_state.size()-1 && j==this->game_state[0].size()-1)
            {
                // Cell is alive
                if(this->game_state[i][j])
                {
                    int sum=this->game_state[i][j-1]+this->game_state[i-1][j-1]+this->game_state[i-1][j];
                    if(sum<=1)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(this->game_state[i][j-1] && this->game_state[i-1][j-1] && this->game_state[i-1][j])
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
            // Top Edge
            else if(i==0)
            {
                int sum=this->game_state[i][j+1]+this->game_state[i+1][j+1]+this->game_state[i+1][j]
                        +this->game_state[i+1][j-1]+this->game_state[i][j-1];
                // Cell is alive
                if(this->game_state[i][j])
                {
                    if(sum<=1 || sum>3)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(sum==3)
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
            // Left Edge
            else if(j==0)
            {
                int sum=this->game_state[i-1][j]+this->game_state[i-1][j+1]+this->game_state[i][j+1]
                        +this->game_state[i+1][j+1]+this->game_state[i+1][j];
                // Cell is alive
                if(this->game_state[i][j])
                {
                    if(sum<=1 || sum>3)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(sum==3)
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
            // Bottom Edge
            else if(i==this->game_state.size()-1)
            {
                int sum=this->game_state[i][j-1]+this->game_state[i-1][j-1]+this->game_state[i-1][j]
                        +this->game_state[i-1][j+1]+this->game_state[i][j+1];
                // Cell is alive
                if(this->game_state[i][j])
                {
                    if(sum<=1 || sum>3)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(sum==3)
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
            // Right Edge
            else if(j==this->game_state[0].size()-1)
            {
                int sum=this->game_state[i+1][j]+this->game_state[i+1][j-1]+this->game_state[i][j-1]
                        +this->game_state[i-1][j-1]+this->game_state[i-1][j];
                // Cell is alive
                if(this->game_state[i][j])
                {
                    if(sum<=1 || sum>3)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(sum==3)
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
            // Everything Else
            else
            {
                int sum=this->game_state[i-1][j]+this->game_state[i-1][j+1]+this->game_state[i][j+1]
                        +this->game_state[i+1][j+1]+this->game_state[i+1][j]+this->game_state[i+1][j-1]
                        +this->game_state[i][j-1]+this->game_state[i-1][j-1];
                // Cell is alive
                if(this->game_state[i][j])
                {
                    if(sum<=1 || sum>3)
                    {
                        temp_state[i][j]=0;
                    }
                }
                // Cell is dead
                else
                {
                    if(sum==3)
                    {
                        temp_state[i][j]=1;
                    }
                }
            }
        }
    }
    this->game_state = temp_state;
}

void GameOfLife::set_board_state(vector<vector<int>> state)
{
    this->game_state=state;
}

vector<vector<int>> GameOfLife::get_board_state()
{
    return this->game_state;
}

ostream& operator<< (ostream& os, const GameOfLife& state)
{
    for(int i=0; i<state.game_state.size()*3; i++)
    {
        os << "-";
    }
    os << endl;
    for(int i=0; i<state.game_state.size(); i++)
    {
        os << "|";
        for(int j=0; j<state.game_state[0].size(); j++)
        {
            if(state.game_state[i][j])
            {
                os << "# ";
            }
            else
            {
                os << "  ";
            }
        }
        os << "|" << endl;
    }
    for(int i=0; i<state.game_state.size()*3; i++)
    {
        os << "-";
    }
    return os;
}
