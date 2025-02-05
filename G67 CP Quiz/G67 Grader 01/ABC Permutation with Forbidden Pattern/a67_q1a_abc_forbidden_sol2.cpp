#include<iostream>
#include<vector>
using namespace std;

void permutation(string &word, int step, int a, int b, int c, int N, vector<string> &wordList, const bool banWords[])
{
    // Termination condition
    if(step == N) { wordList.emplace_back(word); return; }
    else
    {
        char prev = '\0';
        if(step > 0) prev = word[step - 1];
        /*  Add 'A' to a word
            - Has remaining 'A' (a > 0)
            - Check forbidden ("AA", "BA", "CA")    */
        if(a > 0 && !(prev == 'A' && banWords[0]) && !(prev == 'B' && banWords[3]) && !(prev == 'C' && banWords[6]))
        {
            word[step] = 'A';
            permutation(word, step + 1, a - 1, b, c, N, wordList, banWords);
        }
        /*  Add 'B' to a word
            - Has remaining 'B' (b > 0)
            - Check forbidden ("AB", "BB", "CB")    */
        if(b > 0 && !(prev == 'A' && banWords[1]) && !(prev == 'B' && banWords[4]) && !(prev == 'C' && banWords[7]))
        {
            word[step] = 'B';
            permutation(word, step + 1, a, b - 1, c, N, wordList, banWords);
        }
        /*  Add 'C' to a word
            - Has remaining 'C' (c > 0)
            - Check forbidden ("AC", "BC", "CC")    */
        if(c > 0 && !(prev == 'A' && banWords[2]) && !(prev == 'B' && banWords[5]) && !(prev == 'C' && banWords[8]))
        {
            word[step] = 'C';
            permutation(word, step + 1, a, b, c - 1, N, wordList, banWords);
        }
    }
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N,a,b,c,M;
    cin >> N >> a >> b >> c >> M;
    vector<string> wordList;
    bool banWords[9] = {};
    while(M--)
    {
        string ban;
        cin >> ban;
        int index = 3*(ban[0] - 'A') + (ban[1] - 'A');
        banWords[index] = true;
    }
    string word(N, ' ');
    permutation(word, 0, a, b, c, N, wordList, banWords);
    cout << wordList.size() << "\n";
    for(auto &word : wordList)
    {
        cout << word << "\n";
    }
    return 0;
}