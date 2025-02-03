#include<iostream>
#include<queue>
using namespace std;

/**
 * @brief Find maximum circular contiguous sum by using Kadane's Algorithm
 * @details
 * 1.) Find totalSum, minSum and maxSum by using Kadane's Algorithm
 * 2.) Find maximum sum of both normal and circular subarray
 *     Example: Given the array [a1,a2,a3,a4,a5,a6,a7,a8]
 *     - totalSum is a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8
 *     - Normal subarray is [a3,a4,a5] which sum is a3 + a4 + a5
 *     - Circular subarray is [a6,a7,a8,a1,a2] which sum is a6 + a7 + a8 + a1 + a2
 *     From (a6 + a7 + a8 + a1 + a2) = (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8) - (a3 + a4 + a5)
 *     So we can simply find a maximum sum of circular subarray by totalSum - minSum
 * 3.) Output the maximum sum
 *     Case 1: Maximum value is the sum of circular subarray
 *     > Example: [10, -2, -5, -1, -3, 4] <-- totalSum = 3
 *     > maxSum = 10                | [10]
 *     > minSum = -11               | [-2, -5, -1, -3]
 *     > circularSum = 3-(-11) = 14 | [4, 10]
 *     Case 2: Maximum value is the sum of normal subarray
 *     > Example: [8, -4, 3, -5, 4, -10] <-- totalSum = -4
 *     > maxSum = 8                 | [8]
 *     > minSum = -10               | [-10]
 *     > circularSum = -4-(-10) = 6 | [8, -4, 3, -5, 4]
 *     Case 3: All input are negative
 *     > Example: [-1, -2, -3, -4, -5, -6] <-- totalSum = -21
 *     > maxSum = -1                 | [-1]
 *     > minSum = -21                | [-1, -2, -3, -4, -5, -6]
 *     > circularSum = -21-(-21) = 0 | []
 */
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    // Initialize value
    int maxSum = -2147483648; // Lowest int value
    int minSum = 2147483647;  // Highest int value
    int currentMaxSum = 0;
    int currentMinSum = 0;
    int totalSum = 0;
    // Input each number and using Kadane's Algorithm
    int N;
    cin >> N;
    while(N--)
    {
        int num;
        cin >> num;
        totalSum += num;
        // Find currentMaxSum, maxSum
        currentMaxSum += num;
        maxSum = max(currentMaxSum, maxSum);
        // If currentMaxSum is negative, resets currentMaxSum to 0
        currentMaxSum = max(0, currentMaxSum);

        // Find currentMinSum, minSum
        currentMinSum += num;
        minSum = min(currentMinSum, minSum);
        // If currentMinSum is positive, resets currentMinSum to 0
        currentMinSum = min(0, currentMinSum);
    }
    // Output
    // If all number are negative
    if(maxSum < 0) { cout << maxSum; }
    else cout << max(maxSum, totalSum - minSum);
    return 0;
}