#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int N,Q;
    cin >> N >> Q;
    // Input pair of number and its quantity
    vector<pair<long long int, long long int>> numbers(N);
    for(int i = 0; i < N; i++)
    {
        long long int num, quantity;
        cin >> num >> quantity;
        numbers[i] = make_pair(num, quantity);
    }
    // Sort the vector by the number
    sort(numbers.begin(), numbers.end());

    for(auto &[a,b] : numbers)
    {
        cout << "(" << a << ", " << b << ") ";
    }
    cout << endl;
    // Rearrange the data into a map (count, number)
    // Example:
    // > [(4,5), (7,7), (8,3), (9,1), (9,3)]
    // > [(5,4), (12,7), (15,8), (16,9), (19,9)]
    map<long long int, long long int> indexes;
    long long int count = 0;
    for(int i = 0; i < N; i++)
    {
        count += numbers[i].second;
        indexes[count] = numbers[i].first;
    }

    // Input questions
    while(Q--)
    {
        long long int index;
        cin >> index;
        // Use lower_bound to find the smallest index that is more than or equal to index
        auto it = indexes.lower_bound(index);
        cout << (*it).second << "\n";
    }
    return 0;
}