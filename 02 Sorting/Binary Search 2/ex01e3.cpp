#include<iostream>
#include<vector>
using namespace std;
int N,M;

/**
 * @brief A modified binary search to return the greatest value that is less than or equal the target
 *        If there is no such value, return -1
 * @details
 * Example: [10,11,14,15,16,21,68]  | target = 20 | low = 0, high = 6, mid = 3, ans = 15
 *          [16,21,68]              | target = 20 | low = 4, high = 6, mid = 5, ans = 21
 *          [16]                    | target = 20 | low = 4, high = 4, mid = 4, ans = 16
 *          [16] break              | target = 20 | low = 5, high = 4, <------- ans = 16
 *
 * @param numbers is vector of number
 * @param target is target number to search
 * @return ans which is the greatest value that is less than or equal the target
 */
int binarySearch(vector<int> &numbers, int &target)
{
    int low = 0, high = numbers.size() - 1;
    int ans = -1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        
        // Search right half, and store a number
        if(numbers[mid] <= target)
        {
            ans = numbers[mid];
            low = mid + 1;
        }
        // Search left half
        else high = mid-1;
    }
    return ans;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input vectors
    cin >> N >> M;
    vector<int> numbers(N);
    for(int i = 0; i < N; i++) { cin >> numbers[i]; }

    while(M--)
    {
        // Input number
        int num;
        cin >> num;
        cout << binarySearch(numbers, num) << "\n";
    }
    return 0;
}