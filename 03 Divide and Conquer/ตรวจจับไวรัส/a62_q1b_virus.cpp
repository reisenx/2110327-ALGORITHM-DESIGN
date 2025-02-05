#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isDIVOC(vector<int> &virus)
{
    // Terminating condition
    if(virus.size() == 2)
    {
        if(virus[0] == 0 && virus[1] == 1)
            return true;
        else
            return false;
    }
    
    // Split the vector into 2 halves and the mutant of the first half
    vector<int> half01 = vector<int>(virus.begin(), virus.begin() + (virus.size()/2));
    vector<int> half02 = vector<int>(virus.begin() + (virus.size()/2), virus.end());
    vector<int> mutant(half01.begin(), half01.end());
    reverse(mutant.begin(), mutant.end());
    
    // Call the recursive function to split and check them further
    bool condition01 = isDIVOC(half01) && isDIVOC(half02);
    bool condition02 = isDIVOC(mutant) && isDIVOC(half02);
    return condition01 || condition02;
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