#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int N, M;
    cin >> N >> M;
    vector<int> coins(N);
    for(int i = 0; i < N; i++) { cin >> coins[i]; }

    /**
     * ========== Dynamic Programming (DP) ==========
     * amount[a][b] is minimum amount coins picked
     * from type 1 to 'a' that has value equal to 'b'
     * ------------------ Base Case -----------------
     * For money = 0, given amount = 0
     * --------------- More Value coin --------------
     * If the current coin has more value
     * Copy the amount from the row above
     * amounts[type][value] = amounts[type - 1][value]
     * ------------- Pick the current coin -----------
     * Before pick: amounts[picked][value - coin]
     * After pick : amounts[picked][value - coin] + 1
     * ----------- Not Pick the current coin ---------
     * amounts[picked - 1][value]
     * ==============================================
     */
    vector<vector<int>> amounts(N + 1, vector<int>(M + 1, 99999));
    amounts[0][0] = 0;
    for(int picked = 1; picked <= N; picked++) { amounts[picked][0] = 0; }

    for(int picked = 1; picked <= N; picked++)
    {
        int coin = coins[picked - 1];
        for(int value = 1; value <= M; value++)
        {
            if(coin > value)
            {
                amounts[picked][value] = amounts[picked - 1][value];
            }
            else
            {
                int case01 = amounts[picked][value - coin] + 1;
                int case02 = amounts[picked - 1][value];
                amounts[picked][value] = min(case01, case02);
            }
        }
    }

    // Output
    cout << amounts[N][M];
    return 0;
}