#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This make std::cin and std::cout faster
    ios::sync_with_stdio(false); cin.tie(0);

    // Input
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    // Calculate maximum pieces that can be cutted in each length
    // -1 means it is impossible to be cutted
    vector<int> maxPieces(n+1, -1);
    // At length = 0 can be cutted into 0 pieces
    maxPieces[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        // Can be cut into a rope with length 'a'
        if(i >= a && maxPieces[i-a] >= 0)
        {
            maxPieces[i] = max(maxPieces[i], maxPieces[i-a] + 1);
        }
        // Can be cut into a rope with length 'b'
        if(i >= b && maxPieces[i-b] >= 0)
        {
            maxPieces[i] = max(maxPieces[i], maxPieces[i-b] + 1);
        }
        // Can be cut into a rope with length 'c'
        if(i >= c && maxPieces[i-c] >= 0)
        {
            maxPieces[i] = max(maxPieces[i], maxPieces[i-c] + 1);
        }
    }
    // Output
    cout << maxPieces[n];
    return 0;
}