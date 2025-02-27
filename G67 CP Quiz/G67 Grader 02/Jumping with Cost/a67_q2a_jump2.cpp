#include<bits/stdc++.h>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input
    int n,k;
    cin >> n >> k;

    vector<int> a(n), b(k);
    for(int i = 0; i < n; i++) { cin >> a[i]; }
    for(int i = 0; i < k; i++) { cin >> b[i]; }

    // Base Case (From index 0 to k-1)
    vector<int> bestScore(n, 0);
    bestScore[0] = a[0];
    for(int i = 1; i < k; i++)
    {
        // Find the best index to jump from
        int bestJump = INT_MIN;
        for(int j = 0; j < i; j++)
        {
            bestJump = max(bestJump, bestScore[i-j-1] - b[j]);
        }
        bestScore[i] = a[i] + bestJump;
    }

    // Induction Case (From index k-1 to the end)
    for(int i = k; i < n; i++)
    {
        // Find the best index to jump from
        int bestJump = INT_MIN;
        for(int j = 0; j < k; j++)
        {
            bestJump = max(bestJump, bestScore[i-j-1] - b[j]);
        }
        bestScore[i] = a[i] + bestJump;
    }
    
    // Output the best score when reached the end
    cout << bestScore[n-1];
    return 0;
}
