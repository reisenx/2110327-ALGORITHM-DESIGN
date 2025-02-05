#include<iostream>
#include<vector>
using namespace std;

void permutation(string word, int a, int b, int c, int N, vector<string> &wordList, const vector<string> banWords)
{
    if(word.size() == N)
    {
        for(auto &banWord : banWords)
        {
            for(int i = 0; i < word.size() - 1; i++)
            {
                if(word[i] == banWord[0] && word[i+1] == banWord[1])
                {
                    return;
                }
            }
        }
        wordList.push_back(word);
        return;
    }
    else
    {
        if(a > 0)
        {
            permutation(word + 'A', a-1, b, c, N, wordList, banWords);
        }
        if(b > 0)
        {
            permutation(word + 'B', a, b-1, c, N, wordList, banWords);
        }
        if(c > 0)
        {
            permutation(word + 'C', a, b, c-1, N, wordList, banWords);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int N,a,b,c,M;
    cin >> N >> a >> b >> c >> M;
    vector<string> wordList, banWords(M);
    for(int i = 0; i < M; i++)
    {
        cin >> banWords[i];
    }
    permutation("", a, b, c, N, wordList, banWords);
    cout << wordList.size() << endl;
    for(auto &word : wordList)
    {
        cout << word << endl;
    }
    return 0;
}
