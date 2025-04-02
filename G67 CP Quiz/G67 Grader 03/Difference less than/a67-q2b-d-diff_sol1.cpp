#include<iostream>
#include<vector>
#define LL_INT long long int
using namespace std;
LL_INT ans = 0, d;

/**
 * @brief Merge 2 sorted vector together
 * 
 * @param A is sorted vector
 * @param B is another sorted vector
 * @return vector<long long int> as a merged sorted vector
 */
vector<LL_INT> merge(vector<LL_INT> &A, vector<LL_INT> &B)
{
    // Initialize 3 pointer for A, B and C accordingly
    int i = 0, j = 0, k = 0;
    // Initialize a merged vector
    vector<LL_INT> C(A.size() + B.size());

    /**
     * @brief Count amount of pairs A[i], B[j] that |B[j] - A[i]| >= d
     * @details
     * 1. Given 'left' is the index of lowest B[j] that greater or equal than A[i] - d
     * 2. Given 'right' is the index of lowest B[j] that greater than A[i] + d
     *
     * We can guarantee that vector A and B is already sorted.
     * That's why we don't need to reset 'left' and 'right' to 0 each A[i].
     */
    int left = 0, right = 0;
    for(int i = 0; i < A.size(); i++)
    {
        while(left < B.size() && B[left] < A[i] - d) { left++; }
        while(right < B.size() && B[right] <= A[i] + d) { right++; }
        ans += right - left;
    }

    // Merge vector
    while(i < A.size() && j < B.size())
    {
        // Add current element in vector A into vector C
        if(A[i] <= B[j]) { C[k++] = A[i++]; }
        // Add current element in vector B into vector C
        else { C[k++] = B[j++]; }
    }
    // Add remaining element in vector A (has already added every element from vector B)
    while(i < A.size()) { C[k++] = A[i++]; }
    // Add remaining element in vector B (has already added every element from vector A)
    while(j < B.size()) { C[k++] = B[j++]; }
    // Return merged vector
    return C;
}

/**
 * @brief Recursively split vector into 2 parts, then sort and merge each of them.
 * 
 * @param v is a initial vector
 * @param start is a start index of a vector
 * @param stop is a stop index of a vector
 * @return vector<long long int> as a sorted vector 'v'
 */
vector<LL_INT> mergeSort(vector<LL_INT> &v, int start, int stop)
{
    // Base case: Has only 1 element, cannot split it further.
    if(start == stop) return {v[start]};

    // Find midpoint of current vector
    int mid = (start + stop)/2;
    // First half of a vector
    vector<LL_INT> A = mergeSort(v, start, mid);
    // Second half of a vector
    vector<LL_INT> B = mergeSort(v, mid+1, stop);
    // Merged vector
    vector<LL_INT> C = merge(A,B);
    // Return sorted vector
    return C;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int N;
    cin >> N >> d;
    vector<LL_INT> v(N);
    for(int i = 0; i < N; i++) { cin >> v[i]; }

    // Merge sort and output
    vector<LL_INT> sortedVector = mergeSort(v, 0, v.size() - 1);
    cout << ans;
    return 0;
}