#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int n,m;
    cin >> n >> m;
    vector<vector<int>> forest(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> forest[i][j];
        }
    }

    // Dynamic Programming (DP)
    // Calculate the first row of the forest (Can only walk from the left)
    for(int j = 1; j < m; j++) { forest[0][j] += forest[0][j-1]; }
    // Calculate the first column of the forest (Can only walk from above)
    for(int i = 1; i < n; i++) { forest[i][0] += forest[i-1][0]; }
    // Calculate the remaining grid of the forest
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            int fromAbove = forest[i-1][j];
            int fromLeft = forest[i][j-1];
            int fromUpperLeft = forest[i][j] + forest[i-1][j-1];
            forest[i][j] += max(max(fromAbove, fromLeft), fromUpperLeft);
        }
    }

    // Output
    cout << forest[n-1][m-1];
    return 0;
}