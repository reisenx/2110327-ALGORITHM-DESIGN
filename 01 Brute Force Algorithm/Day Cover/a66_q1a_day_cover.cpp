#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> students;

void combination(int pick, int currentStudent)
{

}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int n,m;
    cin >> n >> m;
    students.reserve(m);
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        students[i].reserve(k);
        for(int j = 0; j < k; j++) { cin >> students[i][j]; }
    }


}