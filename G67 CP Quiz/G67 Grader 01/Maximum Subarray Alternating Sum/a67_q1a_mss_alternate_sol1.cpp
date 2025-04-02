#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/**
 * @brief Get the alternating summation S[a->b] from A[a] to A[b]
 *        (Uses S[a-1] and S[b] to calculate)
 * @param a is the start index of the summation
 * @param b is the end index of the summation
 * @param S is the prefix sum of A[i]
 * @return int (alternating summation)
 */
int getAltSum(int a, int b, vector<int> &S)
{
    if(a == 0) return S[b];
    if(a % 2 == 0) return S[b] - S[a-1];
    return S[a-1] - S[b];
}

/**
 * @brief Find the maximum alternating subarray sum (Divide and conquer algorithm)
 * @details
 * There are 3 possible cases
 * ------------------------------------------------------------
 * Case 1: The entire subarray is in the range [left, mid]
 * >> Given maxLeftSum is getMaxAltSum(left, mid, S)
 * >> maxLeftSum is the maximum sum in this case
 * ------------------------------------------------------------
 * Case 2: The entire subarray is in the range [mid + 1, right]
 * >> Given maxRightSum is getMaxAltSum(mid + 1, right, S)
 * >> maxRightSum is the maximum sum in this case
 * ------------------------------------------------------------
 * Case 3: The subarray is in both range (Can be separate into 2 subcases)
 * |-- Case 3.1: 'a' is even
 * |-- Case 3.2: 'a' is odd
 * >> Given 'a' in range [left, mid] and 'b' in range [mid + 1, right]
 * >> Find 'a' that makes S[a -> mid] the maximum value in both cases
 * >> Find 'b' that makes S[a -> b] the maximum value in both cases
 * >> maxCrossSum is the maximum value in both subcases
 * ------------------------------------------------------------
 * Compare these 3 cases and return the highest value among them
 * ------------------------------------------------------------
 * @param left is the start index of the summation
 * @param right is the end index of the summation
 * @param S is the prefix sum of A[i]
 * @return int (maximum alternating summation)
 */
int getMaxAltSum(int left, int right, vector<int> &S)
{
    if(left == right) { return getAltSum(left, right, S); }

    int mid = (left + right)/2;
    int maxLeftSum = getMaxAltSum(left, mid, S);
    int maxRightSum = getMaxAltSum(mid+1, right, S);

    int currentSum;
    int startOdd = left;
    int startEven = left;
    int leftSumOdd = INT_MIN;   // Lowest int in C++ (limit.h library)
    int leftSumEven = INT_MIN;  // Lowest int in C++ (limit.h library)
    for(int i = left; i <= mid; i++)
    {
        currentSum = getAltSum(i, mid, S);
        if(i % 2 == 1 && currentSum > leftSumOdd)
        {
            leftSumOdd = currentSum;
            startOdd = i;
        }
        if(i % 2 == 0 && currentSum > leftSumEven)
        {
            leftSumEven = currentSum;
            startEven = i;
        }
    }

    int maxCrossSumOdd = INT_MIN;   // Lowest int in C++ (limit.h library)
    int maxCrossSumEven = INT_MIN;  // Lowest int in C++ (limit.h library)
    int currentSumOdd, currentSumEven;
    for(int i = mid + 1; i <= right; i++)
    {
        currentSumOdd = getAltSum(startOdd, i, S);
        currentSumEven = getAltSum(startEven, i, S);
        maxCrossSumOdd = max(maxCrossSumOdd, currentSumOdd);
        maxCrossSumEven = max(maxCrossSumEven, currentSumEven);
    }
    int maxCrossSum = max(maxCrossSumOdd, maxCrossSumEven);

    return max(max(maxLeftSum, maxRightSum), maxCrossSum);
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input numbers (A[i]) and its prefix alternating sum (S[i])
    int N;
    cin >> N;
    vector<int> A(N), S(N);
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
        if(i == 0) { S[i] = A[i]; }
        else if(i % 2 == 1) { S[i] = S[i-1] - A[i]; }
        else { S[i] = S[i-1] + A[i]; }
    }

    // Output
    cout << getMaxAltSum(0, N-1, S);
    return 0;
}
