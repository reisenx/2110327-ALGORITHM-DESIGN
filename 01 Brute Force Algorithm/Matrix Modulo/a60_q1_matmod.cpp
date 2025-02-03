#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Calculate (matrix A) mod k and modifying it.
 *        A       = [[a,b], [c,d]]
 *        A mod k = [[a mod k, b mod k], [c mod k, d mod k]]
 * @param A is a 2x2 matrix
 * @param k is a divisor
 */
void moduloMatrix(vector<int> &A, int k)
{
    for(size_t i = 0; i < A.size(); i++) { A[i] %= k; }
}

/**
 * @brief Calculate (AB) mod k
 *        A  is | A0  A1 |
 *              | A2  A3 |
 *        B  is | B0  B1 |
 *              | B2  B3 |
 *        AB is | A0*B0 + A1*B1  A0*B1 + A1*B3 |
 *              | A2*B0 + A3*B1  A2*B1 + A3*B3 |
 * @param A is a 2x2 matrix
 * @param B is a 2x2 matrix
 * @param k is a divisor
 * @return result which is (AB) mod k
 */
vector<int> multiplyMatrix(vector<int> &A, vector<int> &B, int k)
{
    moduloMatrix(A, k);
    moduloMatrix(B, k);
    vector<int> result(4);
    result[0] = ((A[0]*B[0]) % k) + ((A[1]*B[2]) % k);
    result[1] = ((A[0]*B[1]) % k) + ((A[1]*B[3]) % k);
    result[2] = ((A[2]*B[0]) % k) + ((A[3]*B[2]) % k);
    result[3] = ((A[2]*B[1]) % k) + ((A[3]*B[3]) % k);
    moduloMatrix(result, k);
    return result;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    // Input value
    int n,k;
    cin >> n >> k;
    vector<int> A(4);
    for(int i = 0; i < 4; i++) { cin >> A[i]; }
    
    // Calculate (A^n) mod k
    // For more details, read ex01e4.cpp (Mod Expo)
    vector<int> result = {1,0,0,1}; // Use Identity Matrix as an initial value
    moduloMatrix(A, k);
    while(n > 0)
    {
        if(n % 2 == 1) { result = multiplyMatrix(result, A, k); }
        A = multiplyMatrix(A, A, k);
        n /= 2;
    }
    // Output
    for(int &num : result) { cout << num << " "; }
    return 0;
}