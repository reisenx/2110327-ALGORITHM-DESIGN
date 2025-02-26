#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int N;
    cin >> N;
    vector<int> customer(N), totalCustomer(N);
    for(int i = 0; i < N; i++) { cin >> customer[i]; }

    // Calculate maximum customer
    // Given totalCustomer[i] is the maximum customer possible in index i
    for(int i = 0; i < N; i++)
    {
        // Base case (i = 0,1,2,3)
        // i = 0: Can only pick customer[0]
        // i = 1: Can pick customer[0] or customer[1]
        // i = 2: Can pick customer[0] or customer[1] or customer[2]
        // i = 3: Can pick customer[0] + customer[3] or customer[1] or customer[2]
        if(i == 0) { totalCustomer[0] = customer[0]; }
        else if(i == 1) { totalCustomer[1] = max(customer[0], customer[1]); }
        else if(i == 2) 
        {
            totalCustomer[2] = max(totalCustomer[1], customer[2]);
        }
        else if(i == 3)
        {
            totalCustomer[3] = max(totalCustomer[2], customer[0] + customer[3]);
        }
        // Induction case (i > 3)
        // It is guarantee that index i-1, i-2, i-3 and i-4 are already the maximum value
        // So we need to find the maximum value between only 2 cases
        else
        {
            totalCustomer[i] = customer[i] + max(totalCustomer[i-4], totalCustomer[i-3]);
        }
    }
    // Output
    // There's 3 possible cases: The sequence ends in index N-3 or N-2 or N-1
    cout << max(max(totalCustomer[N-3], totalCustomer[N-2]), totalCustomer[N-1]);
    return 0;
}