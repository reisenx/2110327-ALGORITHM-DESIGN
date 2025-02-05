#include<iostream>
using namespace std;

bool isSimilar(string &a, string &b)
{
    // Terminating condition
    if(a == b) return true;
    else
    {
        // Terminating condition (Cannot split it further)
        if(a.size() < 2 || b.size() < 2) return false;
        // Split the string into 2 halves
        // Method used: substr(start, length)
        string a1 = a.substr(0, a.size()/2);
        string a2 = a.substr(a.size()/2);
        string b1 = b.substr(0, b.size()/2);
        string b2 = b.substr(b.size()/2);

        // Call recursive function to split and check it further
        bool condition01 = isSimilar(a1, b1) && isSimilar(a2, b2);
        bool condition02 = isSimilar(a1, b2) && isSimilar(a2, b1);
        return condition01 || condition02;
    }
}

int main()
{
    // This makes std::cin and std::cout faster
    ios::sync_with_stdio(false); cin.tie(0);

    // Input
    string a,b;
    cin >> a >> b;
    // Output
    if(isSimilar(a,b)) cout << "YES";
    else cout << "NO";
    return 0;
}