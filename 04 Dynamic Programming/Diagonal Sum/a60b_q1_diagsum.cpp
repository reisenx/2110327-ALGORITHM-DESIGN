#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Modified Kadane's Algorithm to find maximum diagonal sum
 * 
 * @param table is a 2D array
 * @param x is the start point (row)
 * @param y is the start point (column)
 * @return int - the maximum diagonal sum
 */
int maxDiagonalSum(vector<vector<int>> &table, int x, int y)
{
    int maxSum = table[x][y];
    int currentSum = table[x][y];
    int loops = min(table.size() - x, table.size() - y);
    for(int i = 1; i < loops; i++)
    {
        currentSum = max(currentSum + table[x + i][y + i], table[x + i][y + i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int n;
    cin >> n;
    vector<vector<int>> table(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> table[i][j];
        }
    }

    // Calculate maximum diagonal sum
    int maxSum = maxDiagonalSum(table, 0, 0);
    for(int i = 0; i < n; i++)
    {
        // Case 1: Start point is in [0][0], [0][1], ..., [0][n-1]
        maxSum = max(maxSum, maxDiagonalSum(table, 0, i));
        // Case 2: Start point is in [1][0], [2][0], ..., [n-1][0]
        maxSum = max(maxSum, maxDiagonalSum(table, i, 0));
    }
    // Output
    cout << maxSum;
    return 0;
}