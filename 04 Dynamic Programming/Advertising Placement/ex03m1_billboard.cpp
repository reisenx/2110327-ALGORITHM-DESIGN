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
        // Base case (i = 0,1,2)
        // i = 0: Can only pick customer[0]
        // i = 1: Can pick customer[0] or customer[1]
        // i = 2: Can pick both customer[0] and customer[2] or only customer[1]
        if(i == 0) { totalCustomer[0] = customer[0]; }
        else if(i == 1) { totalCustomer[1] = max(customer[0], customer[1]); }
        else if(i == 2) 
        {
            totalCustomer[i] = max(customer[0] + customer[2], customer[1]);
        }
        // Induction case (i > 2)
        // It is guarantee that index i-1, i-2 and i-3 are already the maximum value
        // So we need to find the maximum value between only 2 cases
        else
        {
            totalCustomer[i] = customer[i] + max(totalCustomer[i-3], totalCustomer[i-2]);
        }
    }
    // Output
    // There's 2 possible cases: The sequence ends in index N-2 or index N-1
    cout << max(totalCustomer[N-2], totalCustomer[N-1]);
    return 0;
}