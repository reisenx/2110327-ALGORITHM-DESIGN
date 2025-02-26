#include<iostream>
#include<vector>
#define mod 1997
using namespace std;

int addMod(int a, int b) { return ((a % mod) + (b % mod)) % mod; }
int multMod(int a, int b) { return ((a % mod) * (b % mod)) % mod; }

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    /**
     * =================== Dynamic Programming (DP) ==================
     * C[n][k] is a ways to separate 'n' rock into 'k' piles
     * -------------------------- Base Case --------------------------
     * C[n][n] = 1 (Every pile has 1 rock)
     * C[n][1] = 1 (Every rocks are in 1 pile)
     * C[n][0] = 0 (n > 0; Impossible to separate to 0 piles)
     * C[0][0] = 1 (0 pile with 0 rock is nothing)
     * ---------------- The n-th rock forms a new pile ---------------
     * Step 1: Forms 'k-1' piles with 'n-1' rock          | C[n-1][k-1]
     * Step 2: Forms 1 piles with 1 rock                  | 1
     * > Count = C[n-1][k-1]
     * ------------- The n-th rock joins a existing pile -------------
     * Step 1: Forms 'k' piles with 'n-1' rock            | C[n-1][k]
     * Step 2: Select 1 from 'k' piles to place a rock    | k
     * > Count = k * C[n-1][k]
     * ---------------------------------------------------------------
     * Formula: C[n][k] = C[n-1][k-1] + (k * C[n-1][k])
     * ===============================================================
     */
    vector<vector<int>> C(501, vector<int>(501, 0));
    C[0][0] = 1;
    for(int n = 1; n <= 500; n++) { C[n][1] = 1; C[n][n] = 1; }
    for(int n = 1; n <= 500; n++)
    {
        for(int k = 2; k < n; k++)
        {
            C[n][k] = addMod(C[n-1][k-1], multMod(k, C[n-1][k]));
        }
    }

    // Input
    int n,k;
    cin >> n >> k;
    // Output
    cout << C[n][k];
    return 0;
}