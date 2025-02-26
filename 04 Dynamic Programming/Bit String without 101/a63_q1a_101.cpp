#include<iostream>
#include<vector>
#define mod 100000007
#define LONG_INT unsigned long long int
using namespace std;

LONG_INT addMod(LONG_INT a, LONG_INT b)
{
    return ((a % mod) + (b % mod)) % mod;
}

LONG_INT multMod(LONG_INT a, LONG_INT b)
{
    return ((a % mod) * (b % mod)) % mod;
}

void multiplyMatrix(vector<vector<LONG_INT>> &A, vector<vector<LONG_INT>> &B, vector<vector<LONG_INT>> &C)
{
    for(int row = 0; row < A.size(); row++)
    {
        for(int col = 0; col < B[0].size(); col++)
        {
            for(int i = 0; i < A[0].size(); i++)
            {
                C[row][col] = addMod(C[row][col], multMod(A[row][i], B[i][col]));
            }
        }
    }
    return;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    /**
     * ===================== State Transition =====================
     * Given q00[n] is amount of length 'n' string the ends with 00
     * Given q01[n] is amount of length 'n' string the ends with 01
     * Given q10[n] is amount of length 'n' string the ends with 10
     * Given q11[n] is amount of length 'n' string the ends with 11
     * q00 --- 0 ---> q00 | q00 --- 1 ---> q01
     * q01 --- 0 ---> q10 | q01 --- 1 ---> q11
     * q10 --- 0 ---> q00 | q10 --- 1 ---> XXX
     * q11 --- 0 ---> q10 | q11 --- 1 ---> q11
     * ===================== Linear Algebra 1 =====================
     * Simply use Linear Algebra (Ax = B) to calculate
     * | 1 0 1 0 |   | q00[n] |   | q00[n] + q10[n] |   | q00[n+1] |
     * | 1 0 0 0 | x | q01[n] | = |      q00[n]     | = | q01[n+1] |
     * | 0 1 0 1 |   | q10[n] |   | q01[n] + q11[n] |   | q10[n+1] |
     * | 0 1 0 1 |   | q11[n] |   | q01[n] + q11[n] |   | q11[n+1] |
     * 
     *            k
     * | 1 0 1 0 |   | q00[n] |   | q00[n+k] |
     * | 1 0 0 0 | x | q01[n] | = | q01[n+k] |
     * | 0 1 0 1 |   | q10[n] |   | q10[n+k] |
     * | 0 1 0 1 |   | q11[n] |   | q11[n+k] |
     *
     * ===================== Linear Algebra 2 =====================
     * To find q00[n], q01[n], q10[n], q11[n] when n is large
     * We will separate 'n' into binary
     * Example: n = 13
     * > We will separate 13 into 1 + 0 + 4 + 8
     * > and calculate (A^8)(A^4)(Ax) instead of (A^13)x;
     * So we need to find A, A^2, A^4, A^8, ..., A^40 beforehand
     * =============================================================
     */

    vector<vector<vector<LONG_INT>>> A(41, vector<vector<LONG_INT>>(4, vector<LONG_INT>(4, 0)));
    A[0] = {{1, 0, 1, 0},
            {1, 0, 0, 0},
            {0, 1, 0, 1},
            {0, 1, 0, 1}};
    for(int i = 1; i < 41; i++)
    {
        multiplyMatrix(A[i-1], A[i-1], A[i]);
    }

    /**
     * ========== Shift Left (<<) ==========
     * a << b means a * (2^b)
     * Example: 5 << 2
     * - 5 in binary 101
     * - Shift Left 2 times, and get 10100
     * - 10100 is 20
     * - 5 << 2 is 20
     * ========== Bitwise And (&) ==========
     * To check if the digit in binary is 0 or 1
     * We can use bitwise and to check
     * - 10100 & 00001 is 00000 (false)
     * - 10100 & 00010 is 00000 (false)
     * - 10100 & 00100 is 00100 (true)
     * - 10100 & 01000 is 00000 (false)
     * - 10100 & 10000 is 10000 (true)
     * =====================================
     */
    
    LONG_INT n;
    cin >> n;
    if(n == 0) { cout << 0; return 0; }
    if(n == 1) { cout << 2; return 0; }
    if(n == 2) { cout << 4; return 0; }
    n -= 2;

    vector<vector<LONG_INT>> q(4, vector<LONG_INT>(1, 0));
    q = {{1}, {1}, {1}, {1}}; // State q00, q01, q10, q11 of length = 2
    for(int i = 0; i < 41; i++)
    {
        if((1LL << i) & n)
        {
            vector<vector<LONG_INT>> temp(4, vector<LONG_INT>(1, 0));
            multiplyMatrix(A[i], q, temp);
            q = temp;
        }
    }

    LONG_INT sum = 0;
    for(int i = 0; i < 4; i++)
    {
        sum = addMod(sum, q[i][0]);
    }
    cout << sum;
    return 0;
}