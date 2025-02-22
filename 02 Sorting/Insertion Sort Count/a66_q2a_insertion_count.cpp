#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input vector A and each number index
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; i++) { cin >> A[i]; }

    // Output
    while(m--)
    {
        int k, count = 0;
        cin >> k;
        // Insertion means shifting the number to the left when it is smaller than the left one.
        // So the answer is to count how many numbers in the left that is greater.
        for(int i = 0; i < n; i++)
        {
            if(A[i] == k) break;
            if(k < A[i]) { count++; }
        }
        cout << count << endl;
    }
    return 0;
}