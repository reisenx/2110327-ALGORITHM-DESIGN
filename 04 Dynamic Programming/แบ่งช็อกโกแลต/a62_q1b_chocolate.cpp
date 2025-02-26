#include<iostream>
#include<vector>
#include<algorithm>
#define mod 1000003
#define LONG_INT unsigned long long int
using namespace std;

LONG_INT addMod(LONG_INT a, LONG_INT b) { return ((a % mod) + (b % mod)) % mod; }
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input
    LONG_INT n,k;
    cin >> n >> k;
    vector<LONG_INT> ways(n + 1, 0);
    vector<LONG_INT> amounts(k);
    for(LONG_INT i = 0; i < k; i++) { cin >> amounts[i]; }
    sort(amounts.begin(), amounts.end());

    /**
     * ========== Dynamic Programming (DP) ==========
     * Example: n = 4 and amount = {1, 3}
     * Initialize: [0,1,0,0,1,0]
     * length = 1
     * > 1 + 1 = 2 | ways = [0,{1},{1},1,0]
     * > 1 + 3 = 4 | ways = [0,{1},1,1,{1}]
     * length = 2
     * > 2 + 1 = 3 | ways = [0,1,{1},{2},1]
     * length = 3
     * > 3 + 1 = 4 | ways = [0,1,1,{2},{3}]
     * Answer = 3
     * ==============================================
     */
    for(LONG_INT &amount : amounts) { ways[amount] = 1; }
    for(LONG_INT piece = 1; piece <= n; piece++)
    {
        for(LONG_INT &amount : amounts)
        {
            if(piece + amount <= n)
            {
                ways[piece + amount] = addMod(ways[piece + amount], ways[piece]);
            }
        }
    }
    // Output
    cout << ways[n];
    return 0;
}