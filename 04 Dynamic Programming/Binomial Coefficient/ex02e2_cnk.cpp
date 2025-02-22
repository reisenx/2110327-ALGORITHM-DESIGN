#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Initialize Binomial Coefficient 2D vector
    vector<vector<int>> C(31, vector<int>(31, 0));
    for(int n = 0; n < 31; n++)
    {
        for(int k = 0; k <= n; k++)
        {
            if(k == 0 || n == k) C[n][k] = 1;
            else C[n][k] = C[n-1][k] + C[n-1][k-1];
        }
    }
    // Input & Output
    int n,k;
    cin >> n >> k;
    cout << C[n][k];
    return 0;
}