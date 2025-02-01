#include<iostream>
#include<vector>
using namespace std;
int row, col;

/**
 * @brief Check if the coordinates (r,c) is still inside a map
 *
 * @param r is current row number
 * @param c is current column number
 * @return true if the coordinates (r,c) is inside a map
 * @return false the coordinates (r,c) is outside a map
 */
bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < row && c < col;
}

/**
 * @brief Use Depth First Search (DFS) algorithm to find all possible path
 *
 * @param r is current row number
 * @param c is current column number
 * @param path is a string contains 'A', 'B', and 'C' to indicate the movement
 * @param map is a map (0 is normal cell | 1 is prohibited cell)
 */
void pathfinder(int r, int c, string path, vector<vector<int>> &map)
{
    // Mark the cell as visited
    map[r][c] = 1;
    // Output when reaching coordinate (row,col) of a map
    if(r == row - 1 && c == col - 1) { cout << path << "\n"; }
    else
    {
        // Move right
        if(isValid(r,c+1) && map[r][c+1] == 0)
            pathfinder(r,c+1,path + 'A', map);
        // Move up
        if(isValid(r+1,c) && map[r+1][c] == 0)
            pathfinder(r+1,c,path + 'B', map);
        // Move down
        if(isValid(r-1,c) && map[r-1][c] == 0)
            pathfinder(r-1,c,path + 'C', map);
    }
    // Unmark the cell as visited
    map[r][c] = 0;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input size of a map
    cin >> row >> col;
    // Input map
    vector<vector<int>> map(row, vector<int>(col));
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            cin >> map[r][c];
        }
    }

    // Call pathfinder to find all possible path
    pathfinder(0, 0, "", map);
    cout << "DONE";
}