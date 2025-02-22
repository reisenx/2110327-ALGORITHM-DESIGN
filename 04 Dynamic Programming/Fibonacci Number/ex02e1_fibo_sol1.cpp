#include<iostream>
#include<vector>
using namespace std;

int fibonacci(int N, vector<int> &allFibonacci)
{
    if(N < allFibonacci.size()) 
        return allFibonacci[N];
    
    int result = fibonacci(N-2, allFibonacci) + fibonacci(N-1, allFibonacci);
    allFibonacci.push_back(result);
    return result;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N;
    vector<int> allFibonacci = {0, 1};
    cin >> N;
    cout << fibonacci(N, allFibonacci);
    return 0;
}