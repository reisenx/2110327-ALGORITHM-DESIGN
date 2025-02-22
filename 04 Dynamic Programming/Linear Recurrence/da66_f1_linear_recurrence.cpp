#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Calculates R(n) mod 32717 by using dynamic programming
 * @details
 * ------------------- Linear Recurrence Formula --------------------
 * R(n) = a[n]                                              | n < k
 * R(n) = c[0]*R[n-1] + c[1]*R[n-2] + ... + c[k-1]*R[n-k]   | n >= k
 * ------------------------ Modulo Formula --------------------------
 * (a*b) mod k = ((a mod k)*(b mod k)) mod k
 * (a+b) mod k = ((a mod k)+(b mod k)) mod k
 * ---------------------- Dynamic Programming -----------------------
 * 1. If R(n) is already calculated, return them 
 *    (Check if R(n) is changed from -1 to something else)
 * 2. If n < k, just return a[n]
 * 3. If n >= k, use for loop to add multiple terms of the equation
 * ------------------------------------------------------------------
 * @param n is a constant
 * @param k is a constant
 * @param c is a sequence c[0] to c[k-1]
 * @param a is a sequence a[0] to a[k-1]
 * @param R is a memory of R(n) results
 * @return int which is R(n) mod 32717
 */
int linearRecurrence(int n, int k, vector<int> &c, vector<int> &a, vector<int> &R)
{
    if(R[n] != -1) { return R[n]; }
    if(n < k)
    {
        R[n] = a[n] % 32717;
        return R[n];
    }
    int result = 0, term = 0;
    for(int i = 0; i < k; i++)
    {
        term = ((c[i] % 32717) * (linearRecurrence(n-i-1, k, c, a, R) % 32717)) % 32717;
        result = ((result % 32717) + (term % 32717)) % 32717;
    }
    R[n] = result;
    return R[n];
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    // Input n,k
    int n,k;
    cin >> k >> n;
    // Input sequence c (c[0] to c[k-1])
    vector<int> c(k);
    for(int i = 0; i < k; i++) { cin >> c[i]; }
    // Input sequence a (a[0] to a[k-1])
    vector<int> a(k);
    for(int i = 0; i < k; i++) { cin >> a[i]; }
    // Initialize memory (initial value = -1)
    vector<int> R(n+1, -1);

    // Output
    cout << linearRecurrence(n, k, c, a, R);
    return 0;
}