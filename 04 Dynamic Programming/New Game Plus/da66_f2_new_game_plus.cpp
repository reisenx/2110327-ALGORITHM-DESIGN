#include<iostream>
#include<vector>
#define mod 100000007
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int R,C;
    cin >> R >> C;
    vector<vector<int>> mark(R, vector<int>(C, 0));
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> mark[i][j];
        }
    }

    // Dynamic Programming (DP)
    vector<vector<vector<int>>> map(R, vector<vector<int>>(C, vector<int>(3, 0)));
    // Column 1 calculation
    for(int i = 0; i < R; i++)
    {
        if(mark[i][0] == 0)
        {
            // Walk by using door X
            if(i - 1 >= 0 && i - 1 < R) { map[i][0][0] = 1; }
            // Walk by using door Y
            map[i][0][1] = 1;
            // Walk by using door Z
            if(i + 1 >= 0 && i + 1 < R) { map[i][0][2] = 1; }
        }
    }

    for(int i = 1; i < R; i++)
    {
        
    }
}