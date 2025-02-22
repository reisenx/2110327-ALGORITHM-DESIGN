#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// Shorten unsigned long long int to ULLONG_INT
#define ULLONG_INT unsigned long long int

/**
 * @brief Calculate total customer from the given time
 * 
 * @param time is the given time
 * @param chef is seating time of each chef
 * @return ULLONG_INT total customer
 */
ULLONG_INT totalCustomer(ULLONG_INT time, vector<ULLONG_INT> &chef)
{
    // At time = 0, total customer = total chef
    ULLONG_INT customers = chef.size();
    // Calculate customer amount of each chef, then add up.
    for(ULLONG_INT seatTime : chef)
    {
        customers += time / seatTime;
    }
    // Return total customers
    return customers;
}

/**
 * @brief Binary search function to find the time needed to use for 'target' customers
 *
 * @param low is lower bound of binary search range (time)
 * @param high is upper bound of binary search range (time)
 * @param target is amount of customer needed
 * @param chef is seating time of each chef
 * @return ULLONG_INT - lowest time that can handle more than or equal 'target' customers
 */
ULLONG_INT binarySearch(ULLONG_INT low, ULLONG_INT high, ULLONG_INT target, vector<ULLONG_INT> &chef)
{
    ULLONG_INT ans = 0;
    while(low <= high)
    {
        // Find mid point of a range
        ULLONG_INT mid = low + (high - low) / 2;
        // Consider second half
        if(totalCustomer(mid, chef) >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        // Consider first half
        else { low = mid + 1; }
    }
    // Return the lowest time that can handle more than or equal 'target' customers
    return ans;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    ULLONG_INT N, A;
    cin >> N >> A;
    vector<ULLONG_INT> chef(N);
    for(int i = 0; i < N; i++) { cin >> chef[i]; }

    // Calculate and output total time
    while(A--)
    {
        ULLONG_INT customer, ans;
        cin >> customer;
        // If amount of customer is less than amount of chef
        if(customer <= chef.size()) { ans = 0; }
        // Use binary search for normal cases
        else { ans = binarySearch(0, ULLONG_MAX, customer, chef); }
        cout << ans << endl;
    }
    return 0;
}