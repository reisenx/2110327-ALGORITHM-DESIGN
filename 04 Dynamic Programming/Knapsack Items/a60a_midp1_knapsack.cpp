#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int n,m;
    cin >> n >> m;
    vector<int> v(n), w(n);
    for(int i = 0; i < n; i++) { cin >> v[i]; }
    for(int i = 0; i < n; i++) { cin >> w[i]; }
    vector<vector<int>> V(n+1, vector<int>(m+1, 0));
    for(int a = 0; a <= n; a++)
    {
        for(int b = 0; b <= m; b++)
        {
            cin >> V[a][b];
        }
    }
    
    // Trace the solution
    vector<int> used;
    int a = n, b = m;
    while(a > 0 && b > 0)
    {
        if(b >= w[a - 1])
        {
            if(V[a][b] == V[a-1][b - w[a - 1]] + v[a - 1])
            {
                used.push_back(a);
                b -= w[a - 1];
            }
        }
        a--;
    }

    // Output
    cout << used.size() << endl;
    for(int &item : used)
    {
        cout << item << " ";
    }
    return 0;
}