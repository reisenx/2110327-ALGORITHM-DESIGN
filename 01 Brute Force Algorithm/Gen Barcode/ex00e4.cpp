#include<iostream>
using namespace std;
int A,B;

/**
 * @brief Add '0' and '1' to a string and output only a string that has exactly 'A' ones
 *
 * @param nums is a string contains '0' and '1'
 * @param ones is a amount of ones in a string
 */
void recursive(string nums, int ones)
{
    // Output when the string length is equal to B
    if(nums.size() == B)
    {
        // Output only a string that has exactly 'A' ones
        if(ones == A) cout << nums << "\n";
        return;
    }
    else
    {
        // Add '0' to a string
        recursive(nums + '0', ones);
        // Add '1' to a string
        recursive(nums + '1', ones + 1);
    }
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input and output
    cin >> A >> B;
    recursive("", 0);
    return 0;
}