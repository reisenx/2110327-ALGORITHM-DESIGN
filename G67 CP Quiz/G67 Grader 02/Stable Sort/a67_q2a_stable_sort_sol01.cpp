#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    // Input
    int n,m;
    cin >> n >> m;
    vector<int> unsorted(n);
    for(int i = 0; i < n; i++)
    {
        cin >> unsorted[i];
    }

    while(m--)
    {
        bool isSorted = true;
        bool isStable = true;
        vector<int> sorted(n), idx(n);
        for(int i = 0; i < n; i++)
        {
            cin >> idx[i];
            sorted[i] = unsorted[idx[i] - 1];
        }
        for(int i = 1; i < n; i++)
        {
            if(sorted[i-1] > sorted[i])
            {
                isSorted = false;
                isStable = false;
                break;
            }
            if(sorted[i-1] == sorted[i])
            {
                if(idx[i-1] > idx[i])
                {
                    isStable = false;
                }
            }
        }
        if(isSorted) { cout << 1 << " "; }
        else { cout << 0 << " "; }
        if(isStable) { cout << 1 << "\n"; }
        else { cout << 0 << "\n"; }
    }
    return 0;
}
