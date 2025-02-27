#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Recursively construct possible movement in a game
 * 
 * @param move is a string contains movement of a player
 * @param step is current step of the move
 * @param ceiling is ceiling height
 * @param current is current height
 */
void recur(string move, int step, int ceiling, int current)
{
    // The play crashes to the floor or ceiling
    if(current <= 0 || current > ceiling) { return; }
    
    // Output movement when the a finish a game
    if(step == 0) { cout << move << "\n"; return; }

    // Move down ('D')
    recur(move + 'D', step - 1, ceiling, current - 1);
    // Doesn't move ('S')
    recur(move + 'S', step - 1, ceiling, current);
    // Move up ('U')
    recur(move + 'U', step - 1, ceiling, current + 1);
}   

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input step, ceiling height, initial height
    int step, ceiling, initial;
    cin >> step >> ceiling >> initial;
    // Call a function and output
    recur("", step, ceiling, initial);
    return 0;
}
