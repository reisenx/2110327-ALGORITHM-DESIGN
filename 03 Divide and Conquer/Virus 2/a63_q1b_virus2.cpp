#include<iostream>
#include<vector>
using namespace std;

bool isDIVOC(vector<int> &virus)
{
    // Terminating condition
    if(virus.size() == 2) return true;

    // Split the vector into 2 halves
    vector<int> half01(virus.begin(), virus.begin() + (virus.size() / 2));
    vector<int> half02(virus.begin() + (virus.size() / 2), virus.end());
    
    // Count ones in both halves
    int ones01 = 0;
    int ones02 = 0;
    for(int i = 0; i < half01.size(); i++)
    {
        if(half01[i] == 1) ones01++;
        if(half02[i] == 1) ones02++;
    }
    if(abs(ones01 - ones02) > 1) return false;

    // Call recursive function to aplit into half and check it further
    return isDIVOC(half01) && isDIVOC(half02);
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input and find all viruses possible
    int n,k;
    cin >> n >> k;
    // The bitwise operation 1 << n is similar to 2^n
    int size = 1 << k;
    
    // Input each virus and check
    while(n--)
    {
        vector<int> virus(size);
        for(int i = 0; i < size; i++) { cin >> virus[i]; }

        if(isDIVOC(virus)) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}