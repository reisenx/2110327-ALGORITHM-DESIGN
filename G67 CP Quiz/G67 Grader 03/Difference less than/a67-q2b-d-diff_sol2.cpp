#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input vector
    int n, d;
    cin >> n >> d;
    vector<long long int> A(n);
    for(int i = 0; i < n; i++) { cin >> A[i]; }

    // Sort the array in ascending order
    sort(A.begin(), A.end());

    // Iterate each number and check if it satisfy |A[j] - A[i]| >= d when i < j
    // Since we need to check all pairs, sorting it then binary search is better
    // Brute force uses O(n^2) | This method uses O(nlog(n))
    long long int ans = 0;
    for(int i = 0; i < n; i++)
    {
        // Find index of the lowest number that greater than A[i] + d
        int j = upper_bound(A.begin() + i + 1, A.end(), A[i] + d) - A.begin();
        // We can assume that all number from A[i] to A[j - 1] are satisfy the problem
        ans += (j - 1) - i;
    }
    
    // Output
    cout << ans;
    return 0;
}