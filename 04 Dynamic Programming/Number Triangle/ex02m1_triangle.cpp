#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int N, maxSum = -1;
    cin >> N;
    vector<vector<int>> triangle(N, vector<int>());
    for(int i = 0; i < N; i++)
    {
        triangle[i].resize(i + 1, 0);
        for(int j = 0; j < i + 1; j++)
        {
            cin >> triangle[i][j];

            // Dynamic Programming
            if(i > 0)
            {
                // Case 1: First number of the row
                // Can be only added with the first number of the row above.
                if(j == 0) { triangle[i][j] += triangle[i-1][j]; }
                // Case 2: Last number of the row
                // Can be only added with the last number of the row above.
                else if(j == i) { triangle[i][j] += triangle[i-1][j-1]; }
                // Case 3: Normal cases
                // Compare between adding with left or right number of the row above
                else { triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]); }
            }
            // Find maximum summation from the lowest row
            // All numbers in the triangle are non-negative numbers
            if(i == N - 1) { maxSum = max(maxSum, triangle[i][j]); }
        }
    }
    // Output
    cout << maxSum;
    return 0;
}