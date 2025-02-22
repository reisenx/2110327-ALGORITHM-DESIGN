#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int minStudents = INT_MAX;
vector<int> daySlots, studentSlots;
vector<vector<int>> students;

/**
 * @brief Recursively pick each student, count and mark day slots, and return amount of student needed
 * 
 * @param studentCount is counter of student needed.
 * @param m is total students
 * @param dayCount is counter of days that already has a student working
 * @param n is total days
 * @param start is start point of student that can be picked
 */
void permutation(int studentCount, int m, int dayCount, int n, int start)
{
    // If the current case is not the best case, stop the permutation.
    if(studentCount >= minStudents) { return; }
    // If the current permutation has student working on everyday.
    if(dayCount == n)
    {
        minStudents = min(minStudents, studentCount); // Find the minimum of student needed
        return;
    }
    // Recursively pick a student in range(start, m)
    for(int i = start; i < m; i++)
    {
        // If the student has not picked yet, pick them.
        if(studentSlots[i] == 0)
        {
            // Marked them as picked.
            studentSlots[i] = 1;
            studentCount++;
            // Marked all days of this student working on.
            vector<int> markedDays;
            for(auto &day : students[i])
            {
                if(daySlots[day - 1] == 0)
                {
                    markedDays.push_back(day - 1);
                    daySlots[day - 1] = 1;
                    dayCount++;
                }
            }
            // Call the function to pick more student
            permutation(studentCount, m, dayCount, n, i + 1);

            // Backtracking
            studentSlots[i] = 0;
            studentCount--;
            for(auto &day : markedDays)
            {
                daySlots[day] = 0;
                dayCount--;
            }
        }
    }
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int n, m, k;
    cin >> n >> m;
    daySlots.resize(n, 0);
    studentSlots.resize(m, 0);
    students.resize(m, vector<int>());
    for(int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        students[i].resize(k);
        for(int j = 0; j < k; j++)
        {
            cin >> students[i][j];
        }
    }

    // Calculate and output minimum students needed
    permutation(0, m, 0, n, 0);
    cout << minStudents;
    return 0;
}