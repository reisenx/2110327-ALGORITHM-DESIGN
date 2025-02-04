#include<iostream>
#include<vector>
using namespace std;

bool tripleSum(int target, const vector<int> &numbers)
{
    for(int k = 0; k < numbers.size(); k++)
    {
        int twoSum = target - numbers[k];
        int i = 0, j = numbers.size() - 1;
        while(i < j)
        {
            // Skip index k
            if(i == k)
                i++;
            else if(j == k)
                j--;
            // Two Sum algorithm
            else
            {
                int sum = numbers[i] + numbers[j];
                if(sum == twoSum) return true;
                else if(sum < twoSum) i++;
                else j--;
            }
        }
    }
    return false;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input array of numbers
    int N, M;
    cin >> N >> M;
    vector<int> numbers(N);
    for(int i = 0; i < N; i++) { cin >> numbers[i]; }
    // Input questions and call tripleSum()
    while(M--)
    {
        int target;
        cin >> target;
        if(tripleSum(target, numbers))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}