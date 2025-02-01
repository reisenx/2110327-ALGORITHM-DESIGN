#include<iostream>
#include<vector>
using namespace std;

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