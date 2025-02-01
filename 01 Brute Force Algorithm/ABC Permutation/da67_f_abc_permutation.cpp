#include<iostream>
#include<vector>
using namespace std;
vector<string> ans;

/**
 * @brief Add 'A', 'B', 'C' to a string recursively, and add all permutations to a queue.
 *
 * @param word is a string contains 'A', 'B', and 'C'
 * @param n is a required length of a word
 * @param a is a required amount of 'A' in a word
 * @param b is a required amount of 'B' in a word
 * @param c is a required amount of 'C' in a word
 */
void recursive(string word, int n, int a, int b, int c)
{
    // If a word reaches the required length, stop the recursion.
    if(n == 0)
    {
        ans.push_back(word);
        return;
    }

    // Add 'A', 'B', and 'C' to a string recursively
    if(a > 0) recursive(word + 'A', n-1, a-1, b, c);
    if(b > 0) recursive(word + 'B', n-1, a, b-1, c);
    if(c > 0) recursive(word + 'C', n-1, a, b, c-1);
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input required string length, and 'A', 'B', 'C' amount.
    int N,A,B,C;
    cin >> N >> A >> B >> C;

    // Call recursive function to obtain all permutations
    recursive("", N, A, B, C);

    // Output
    cout << ans.size() << "\n";
    for(auto &word : ans)
    {
        cout << word << "\n";
    }
}