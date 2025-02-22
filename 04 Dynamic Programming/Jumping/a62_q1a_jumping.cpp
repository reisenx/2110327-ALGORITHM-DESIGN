#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios::sync_with_stdio(false); cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> points(N);
    for(int i = 0; i < N; i++)
    {
        // Input point of each index
        cin >> points[i];
        // Calculate maximum total points of each index
        if(i == 0) { }
        else if(i == 1) { points[i] += points[i-1]; }
        else if(i == 2) { points[i] += max(points[i-1], points[i-2]); }
        else
        {
            points[i] += max(max(points[i-1], points[i-2]), points[i-3]);
        }
    }
    cout << points[N-1];
    return 0;
}