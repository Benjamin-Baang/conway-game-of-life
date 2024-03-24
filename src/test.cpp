#include "gameOfLife.hpp"

int count=1;

void test(vector<vector<int>> expect, vector<vector<int>> ans, int height, int width)
{
    if(expect == ans)
    {
        cout << "PASSED " << count << endl;
    }
    else
    {
        cout << "FAILED " << count << endl;
        cout << "Expected:" << endl;
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                cout << expect[i][j] << " ";
            }
            cout << endl;
        }
        cout << "Actual: " << endl;
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    count++;
}

int main()
{
    int width = 3, height = 3;

    // Test 1: All dead
    vector<vector<int>> state1 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    vector<vector<int>> expect1 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    GameOfLife ans1;
    ans1.set_board_state(state1);
    ans1.next_board_state();

    test(expect1, ans1.get_board_state(), height, width);

    // End of Test 1

    // Test 2: Corners
    vector<vector<int>> state2 = {
        {1, 0, 1},
        {1, 0, 1},
        {1, 0, 1}
    };

    vector<vector<int>> expect2 = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 0, 0}
    };

    GameOfLife ans2;
    ans2.set_board_state(state2);
    ans2.next_board_state();

    test(expect2, ans2.get_board_state(), height, width);

    // End of Test 2

    // Test 3: Edges
    vector<vector<int>> state3 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    vector<vector<int>> expect3 = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}
    };

    GameOfLife ans3;
    ans3.set_board_state(state3);
    ans3.next_board_state();

    test(expect3, ans3.get_board_state(), height, width);

    // End of Test 3

    // Test 4: Turn cell alive
    vector<vector<int>> state4 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    vector<vector<int>> expect4 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    GameOfLife ans4;
    ans4.set_board_state(state4);
    ans4.next_board_state();

    test(expect4, ans4.get_board_state(), height, width);

    // End of Test 4

    // Test 5: All cell alive
    vector<vector<int>> state5 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    vector<vector<int>> expect5 = {
        {1, 0, 1},
        {0, 0, 0},
        {1, 0, 1}
    };

    GameOfLife ans5;
    ans5.set_board_state(state5);
    ans5.next_board_state();

    test(expect5, ans5.get_board_state(), height, width);

    // End of Test 5

    // Test 6: All cell alive
    vector<vector<int>> state6 = {
        {0, 0, 1},
        {0, 1, 1},
        {0, 0, 0}
    };

    vector<vector<int>> expect6 = {
        {0, 1, 1},
        {0, 1, 1},
        {0, 0, 0}
    };

    GameOfLife ans6;
    ans6.set_board_state(state6);
    ans6.next_board_state();

    test(expect6, ans6.get_board_state(), height, width);

    // End of Test 5

    return 0;
}