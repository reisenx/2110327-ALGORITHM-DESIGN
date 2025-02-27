#include<bits/stdc++.h>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input
    int n,m;
    cin >> n >> m;
    vector<int> A(n);
    for(int i = 0; i < n; i++) { cin >> A[i]; }

    while(m--)
    {
        int prevValue, prevIdx, currentValue, currentIdx;
        bool isSorted = true;
        bool isStable = true;
        
        // Input index of the first item
        cin >> currentIdx;
        currentValue = A[currentIdx - 1];
        for(int i = 1; i < n; i++)
        {
            // Store the previous index and value of the first one
            prevIdx = currentIdx;
            prevValue = currentValue;
            
            // Input current index and find a value
            cin >> currentIdx;
            currentValue = A[currentIdx - 1];

            // If the current value is less than previous value
            // The array is not sorted and not stable sort
            if(currentValue < prevValue) 
            {
                isSorted = false;
                isStable = false;
            }
            // If the current value is the same with the previous value
            // Check if the current index is greater than previous index
            if(currentValue == prevValue && currentIdx < prevIdx)
            {
                isStable = false;
            }
        }

        // Output
        if(isSorted) { cout << 1 << " "; }
        else { cout << 0 << " "; }
        if(isStable) { cout << 1 << "\n"; }
        else { cout << 0 << "\n"; }
    }
    return 0;
}
