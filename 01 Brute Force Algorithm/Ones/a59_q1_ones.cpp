#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<int> q = {1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111};

/**
 * @brief Find the least amount of '1' to get the num
 *
 * @param num is an input number
 */
int ones(int num)
{
    // Base case
    // Example: 6 = 1 + 1 + 1 + 1 + 1 + 1
    if(num <= 6) return num;
    // Example: 7 = 11 - 1 - 1 - 1 - 1
    if(num <= 11) return 13 - num;

    // Find q[idx] that is highest but lower than 'num'
    int idx;
    for(idx = 8; idx >= 0; idx--)
    {
        if(q[idx] <= num) break;
    }
    // Check midpoint
    int midpoint = q[idx] + ((q[idx+1] - q[idx]) / 2);
    // Choose q[idx]        (Example: 123 - 111)
    if(num < midpoint) { return ones(num - q[idx]) + (idx + 1); }
    // Choose q[idx + 1]    (Example: 1111 - 123)
    else { return ones(q[idx + 1] - num) + (idx + 2); }
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int num;
    cin >> num;
    // Output
    cout << ones(num);
    return 0;
}
