#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    string A, B;
    cin >> A >> B;

    // ========== Dynamic Programming (DP) ==========
    vector<vector<int>> count(A.size() + 1, vector<int>(B.size() + 1, 0));
    for(int i = 1; i <= A.size(); i++)
    {
        for(int j = 1; j <= B.size(); j++)
        {
            if(A[i-1] == B[j-1])
            {
                count[i][j] = count[i-1][j-1] + 1;
            }
            else { count[i][j] = max(count[i-1][j], count[i][j-1]); }
        }
    }
    // Output
    cout << count[A.size()][B.size()];
    return 0;
}