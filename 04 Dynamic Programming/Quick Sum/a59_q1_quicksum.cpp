#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios::sync_with_stdio(false); cin.tie(0);

    // Input
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> A(N, vector<int>(M)), P(N, vector<int>(M));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> A[i][j];
        }
    }

    // Block Summation Algorithm
    P[0][0] = A[0][0];
    for(int j = 1; j < M; j++)
    {
        P[0][j] = P[0][j-1] + A[0][j];
    }
    for(int i = 1; i < N; i++)
    {
        P[i][0] = P[i-1][0] + A[i][0];
        for(int j = 1; j < M; j++)
        {
            P[i][j] = P[i-1][j] + P[i][j-1] - P[i-1][j-1] + A[i][j];
        }
    }

    // Output
    while(K--)
    {
        int r1, r2, c1, c2, sum;
        cin >> r1 >> c1 >> r2 >> c2;
        // Prefix Sum
        sum = P[r2][c2];
        if(r1 > 0) sum -= P[r1-1][c2];
        if(c1 > 0) sum -= P[r2][c1-1];
        if(r1 > 0 && c1 > 0) sum += P[r1-1][c1-1];
        cout << sum << endl;
    }
    return 0;
}