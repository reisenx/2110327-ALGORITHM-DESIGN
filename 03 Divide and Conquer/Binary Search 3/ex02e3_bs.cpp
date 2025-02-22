#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief A modified binary search to return index of the greatest value that is less than or equal the target
 *        If there is no such value, return -1
 * @details
 * Example: [10,11,14,15,16,21,68]  | target = 20 | low = 0, high = 6, mid = 3, ans = 3
 *          [16,21,68]              | target = 20 | low = 4, high = 6, mid = 5, ans = 5
 *          [16]                    | target = 20 | low = 4, high = 4, mid = 4, ans = 4
 *          [16] break              | target = 20 | low = 5, high = 4, <------- ans = 4
 *
 * @param numbers is vector of number
 * @param target is target number to search
 * @return ans which is index of the greatest value that is less than or equal the target
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
            ans = mid;
            low = mid + 1;
        }
        // Search left half
        else high = mid-1;
    }
    return ans;
}

/**
 * @details 
 * 1.) Input the input array as two vector
 * Example: input   = [10,13,14,14,14,15,16,16,18,200]
 *          numbers = [10,13,14,15,16,18,200]
 *          indexes = [0,1,4,5,7,8,9]
 * 2.) Call binarySearch() function to find a target number
 * Example: binarySearch(numbers, 20) return 4
 * 3.) Convert into a maximum index in actual indexes
 * Example: numbers = [10,13,14,15,{16},18,200]             <-- index = 4
 *          input   = [10,13,14,14,14,15,16,{16},18,200]    <-- index = 7
 *          indexes[4] = 7
 */
int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input vectors
    int N,M;
    cin >> N >> M;
    vector<int> numbers;
    vector<int> indexes;
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        // Unique number: push_back() number and its index
        if(numbers.empty() || num > numbers.back())
        {
            numbers.push_back(num);
            indexes.push_back(i);
        }
        // Duplicate number: Update its largest index
        else if(num == numbers.back())
        {
            indexes.back() = i;
        }
    }

    while(M--)
    {
        // Input number
        int num;
        cin >> num;
        // Get the index in unique numbers vector
        int ans = binarySearch(numbers, num);
        // Convert to the index in non-unique numbers vector
        if(ans >= 0) ans = indexes[ans];
        // Output
        cout << ans << "\n";
    }
    return 0;
}