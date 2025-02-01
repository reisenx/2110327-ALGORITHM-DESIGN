#include<iostream>
using namespace std;
int n,k;

/**
 * @brief Add '0' and '1' to a string and output only a string that has more than or equal 'k' consecutive ones
 *
 * @param nums is a string contains '0' and '1'
 * @param ones is a consecutive ones counter
 * @param done indicates that a string has 'k' consecutive ones
 */
void recursive(string nums, int ones, bool done)
{
    // Check if there are more than or equal k ones
    if(ones >= k) done = true;

    // Output when the string length is equal to n
    if(nums.size() == n)
    {
        if(done) cout << nums << "\n";
        return;
    }
    else
    {
        // Add '0' to a string and reset consecutive ones counter
        recursive(nums + '0', 0, done);
        // Add '1' to a string
        recursive(nums + '1', ones + 1, done);
    }
}

int main()
{
    // This makes std::cin and std::cout faster.
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input and output
    cin >> n >> k;
    recursive("", 0, false);
    return 0;
}