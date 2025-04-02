#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Use Kadane's Algorithm to find maximum alternating sum
 *
 * @param array is an array of numbers
 * @return int - the maximum alternating sum
 */
int maxAltSum(vector<int> &array)
{
    int maxSum = array[0];
    int currentSum = array[0];
    for(int i = 1; i < array.size(); i++)
    {
        currentSum = max(currentSum + array[i], array[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main()
{

}