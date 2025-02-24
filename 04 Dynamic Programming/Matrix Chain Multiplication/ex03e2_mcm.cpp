#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input amount of the matrix and its size
    // Matrix n has a[n] x a[n+1] size
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for(int i = 0; i < N + 1; i++) { cin >> a[i]; }

    // Matrix Chain Multiplication (Dynamic Programming)
    // M[x][x+k] is minimum value of M[x][x+i] + M[i+1][x+k] + a[x]*a[i+1]*a[x+k+1]
    // k in range [1,N] | x in range [0,N - k] | i in range [x, x+k]
    // Loop in diagonal (A[0][1], A[1][2], ..., A[0][2], A[1][3], ..., A[0][3], A[1][4], ...)
    vector<vector<int>> M(N, vector<int>(N, 0));
    for(int k = 1; k < N; k++)
    {
        for(int x = 0; x < N - k; x++)
        {
            M[x][x + k] = INT_MAX;
            for(int i = x; i < x + k; i++)
            {
                int cost = M[x][i] + M[i + 1][x + k] + (a[x] * a[i + 1] * a[x + k + 1]);
                M[x][x + k] = min(M[x][x + k], cost);
            }
        }
    }
    // Output
    cout << M[0][N - 1];
    return 0;
    // NOTE: To understand this, please watch Algorithm Design playlist in nattee115 YouTube channel
}