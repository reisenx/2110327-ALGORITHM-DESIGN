#include<iostream>
using namespace std;

/**
 * @brief Find maximum contiguous sum by using Kadane's Algorithm */
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    // Initialize value
    int maxSum = -2147483648; // Lowest int value
    int currentSum = 0;
    // Input each number and using Kadane's Algorithm
    int N;
    cin >> N;
    while(N--)
    {
        int num;
        cin >> num;
        // Find currentSum and maxSum
        currentSum += num;
        maxSum = max(currentSum, maxSum);
        // If currentSum is negative, resets currentSum to 0
        currentSum = max(0, currentSum);
    }
    // Output
    cout << maxSum;
    return 0;
}