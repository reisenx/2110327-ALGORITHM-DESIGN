#include<iostream>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int N;
    cin >> N;
    int prev = 0, current = 1;
    if(N == 0) cout << prev;
    else
    {
        for(int i = 2; i <= N; i++)
        {
            int temp = current;
            current += prev;
            prev = temp;
        }
        cout << current;
    }
    return 0;
}