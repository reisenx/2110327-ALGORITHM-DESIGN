#include<iostream>
#include<vector>
using namespace std;
int N,M;

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