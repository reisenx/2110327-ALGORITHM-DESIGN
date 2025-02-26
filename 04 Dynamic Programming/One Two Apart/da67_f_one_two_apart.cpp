#include<iostream>
#include<vector>
#define mod 100000007
using namespace std;
vector<vector<int>> state(1000001, vector<int>(7,0));

/**
 * @brief add two number and mod with 100000007
 * 
 * @param a is the first number
 * @param b is the second number
 * @return int as an answer
 */
int addMod(int a, int b)
{
    return ((a % mod) + (b % mod)) % mod;
}

/**
 * @brief add three number and mod with 100000007
 * 
 * @param a is the first number
 * @param b is the second number
 * @param c is the third number
 * @return int as an answer
 */
int addMod(int a, int b, int c)
{
    return ((((a % mod) + (b % mod)) % mod) + (c % mod)) % mod;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    /**
     * ================= Dynamic programming (DP) =================
     * state[i][j] is amount of length i string ends with j
     * i means length of string
     * j means {0:00, 1:01, 2:10, 3:11, 4:02, 5:20, 6:22}
     * ===================== State Transition =====================
     * q00 --- 0 ---> q00 | q00 --- 1 ---> q01 | q00 --- 2 ---> q02
     * q01 --- 0 ---> q10 | q01 --- 1 ---> q11 | q01 --- 2 ---> XXX
     * q10 --- 0 ---> q00 | q10 --- 1 ---> q01 | q10 --- 2 ---> XXX
     * q11 --- 0 ---> q10 | q11 --- 1 ---> q11 | q11 --- 2 ---> XXX
     * q02 --- 0 ---> q20 | q02 --- 1 ---> XXX | q02 --- 2 ---> q22
     * q20 --- 0 ---> q00 | q20 --- 1 ---> XXX | q20 --- 2 ---> q02
     * q22 --- 0 ---> q20 | q22 --- 1 ---> XXX | q22 --- 2 ---> q22
     * ============================================================
     */
    state[0] = {0,0,0,0,0,0,0};
    state[1] = {1,1,0,0,1,0,0};
    state[2] = {1,1,1,1,1,1,1};
    for(int i = 3; i < 1000001; i++)
    {
        state[i][0] = addMod(state[i-1][0], state[i-1][2], state[i-1][5]);
        state[i][1] = addMod(state[i-1][0], state[i-1][2]);
        state[i][2] = addMod(state[i-1][1], state[i-1][3]);
        state[i][3] = addMod(state[i-1][1], state[i-1][3]);
        state[i][4] = addMod(state[i-1][0], state[i-1][5]);
        state[i][5] = addMod(state[i-1][4], state[i-1][6]);
        state[i][6] = addMod(state[i-1][4], state[i-1][6]);
    }
    
    // Input
    int N;
    cin >> N;
    // Output
    int ans = 0;
    for(int i = 0; i < 7; i++)
    {
        ans = addMod(ans, state[N][i]);
    }
    cout << ans;
    return 0;
}