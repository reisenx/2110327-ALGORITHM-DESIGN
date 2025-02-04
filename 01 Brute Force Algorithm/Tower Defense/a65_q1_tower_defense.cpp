#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n,m,w,k;
int totalPower = 0;

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input informations
    cin >> n >> m >> k >> w;
    vector<int> monsterPos(m);
    map<int,int> monsterPower;
    vector<int> towerPos(k);
    // Input monster positions and its power
    // Create a map that each has [position, power]
    for(int i = 0; i < m; i++) { cin >> monsterPos[i]; }
    for(int i = 0; i < m; i++)
    { 
        int power;
        cin >> power;
        monsterPower[monsterPos[i]] = power;
        totalPower += power;
    }

    // Input tower position and sort in ascending order
    for(int i = 0; i < k; i++) { cin >> towerPos[i]; }
    sort(towerPos.begin(), towerPos.end());

    // Each tower shoot the monster
    for(int i = 0; i < k; i++)
    {
        // Find leftmost monster to shoot
        auto it = monsterPower.lower_bound(towerPos[i] - w);
        // If the monster is within range, shoot it
        // Decrease its power by 1. If it's dead, remove it from a map
        if(it != monsterPower.end() && it->first <= towerPos[i] + w)
        {
            totalPower -= 1;
            it->second -= 1;
            if(it->second == 0) { monsterPower.erase(it); }
        }
    }
    // Output
    cout << totalPower;
    return 0;
}