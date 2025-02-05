#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void recurMatrix(int a, int b, int row, int col, vector<vector<int>> &matrix)
{
    // Stop the recursion: H(0,b) = b
    if(a == 0)
    {
        matrix[row][col] = b;
        return;
    }
    /*  Recursion function of H(a,b)
        H(a,b) = H(a-1, b)      | row = 2n   | col = 2n
        H(a,b) = H(a-1, b-1)    | row = 2n   | col = 2n+1
        H(a,b) = H(a-1, b+1)    | row = 2n+1 | col = 2n
        H(a,b) = H(a-1, b)      | row = 2n+1 | col = 2n+1
    */
    else
    {
        recurMatrix(a-1, b,   2*row,     2*col,     matrix);
        recurMatrix(a-1, b-1, 2*row,     2*col + 1, matrix);
        recurMatrix(a-1, b+1, 2*row + 1, 2*col,     matrix);
        recurMatrix(a-1, b,   2*row + 1, 2*col + 1, matrix);
    }
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a,b;
    cin >> a >> b;
    int size = (int) pow(2,a);
    vector<vector<int>> matrix(size, vector<int>(size, 0));
    recurMatrix(a, b, 0, 0, matrix);
    for(auto &row : matrix)
    {
        for(auto &num : row)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}