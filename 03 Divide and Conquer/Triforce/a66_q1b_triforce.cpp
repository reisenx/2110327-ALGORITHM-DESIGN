#include<iostream>
#include<vector>
using namespace std;

/**
 * @brief Check if one of the 3 numbers is 0
 * 
 * @param a is the first number
 * @param b is the second number
 * @param c is the third number
 * @return true if all 3 numbers are not zero
 * @return false is one of the 3 number is zero
 */
bool hasZero(int a, int b, int c)
{
    return (a == 0) || (b == 0) || (c == 0);
}

/**
 * @brief Check if the 2D array in specified range is all zero
 * 
 * @param table is a 2D array
 * @param r1 is the row number of the upper left point
 * @param c1 is the column number of the upper left point
 * @param r2 is the row number of the lower right point
 * @param c2 is the column number of the lower right point
 * @return true if all number in 2D array in specified range is all zero
 * @return false if has at least 1 number in 2D array in specified range is zero
 */
bool isAllZero(vector<vector<int>> &table, int r1, int c1, int r2, int c2)
{
    for(int i = r1; i <= r2; i++)
    {
        for(int j = c1; j <= c2; j++)
        {
            if(table[i][j] != 0) return false;
        }
    }
    return true;
}

/**
 * @brief Get the Duplicate number of the 3 numbers
 * 
 * @param a is the first number
 * @param b is the second number
 * @param c is the third number
 * @return int as the duplicate number (if not found, return 0)
 */
int getDuplicate(int a, int b, int c)
{
    if(a == b && b == c) return a;
    if(a == b) return a;
    if(a == c) return a;
    if(b == c) return b;
    return 0;
}

/**
 * @brief Check if the triforce type of the 2D array
 * 
 * @param table is a 2D array
 * @param r1 is the row number of the upper left point
 * @param c1 is the column number of the upper left point
 * @param r2 is the row number of the lower right point
 * @param c2 is the column number of the lower right point
 * @param width is the width of the current array
 * @return int as the type of triforce (return 0, if it is not)
 */
int triforce(vector<vector<int>> &table, int r1, int c1, int r2, int c2, int width)
{
    // Separate section
    // P: Upper Left | Q: Upper Right
    // ------------------------------
    // R: Lower Left | S: Lower Right
    int P,Q,R,S;

    // Base case (width = 2)
    if(width == 2)
    {
        P = table[r1][c1];
        Q = table[r1][c2];
        R = table[r2][c1];
        S = table[r2][c2];
        // Check section S
        if(S != 0) return 0;
        // Check section P,Q,R
        if(hasZero(P,Q,R)) return 0;
        return getDuplicate(P,Q,R);
    }

    // Split into 4 section
    int r_mid = (r1 + r2) / 2;
    int c_mid = (c1 + c2) / 2;
    // Check section S
    if(!isAllZero(table, r_mid + 1, c_mid + 1, r2, c2)) return 0;
    // Get section P,Q,R
    P = triforce(table, r1,        c1,        r_mid, c_mid, width/2);
    Q = triforce(table, r_mid + 1, c1,        r2,    c_mid, width/2);
    R = triforce(table, r1,        c_mid + 1, r_mid, c2,    width/2);
    // Check section P,Q,R
    if(hasZero(P,Q,R)) return 0;
    return getDuplicate(P,Q,R);
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    int times = 3;
    while(times--)
    {
        // Input
        int width;
        cin >> width;
        vector<vector<int>> table(width, vector<int>(width, 0));
        for(int i = 0; i < width; i++)
        {
            for(int j = 0; j < width; j++)
            {
                cin >> table[i][j];
            }
        }
        // Output
        cout << triforce(table, 0, 0, width-1, width-1, width) << "\n";
    }
    return 0;
}