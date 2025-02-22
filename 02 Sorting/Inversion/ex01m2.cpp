#include<iostream>
#include<vector>
using namespace std;
int ans = 0;

/**
 * @brief Merge 2 sorted vector together
 * 
 * @param A is sorted vector
 * @param B is another sorted vector
 * @return vector<int> as a merged sorted vector
 */
vector<int> merge(vector<int> &A, vector<int> &B)
{
    // Initialize 3 pointer for A, B and C accordingly
    int i = 0, j = 0, k = 0;
    // Initialize a merged vector
    vector<int> C(A.size() + B.size());
    // Merge vector
    while(i < A.size() && j < B.size())
    {
        // Add current element in vector A into vector C
        if(A[i] <= B[j]) { C[k++] = A[i++]; }
        // Add current element in vector B into vector C
        // Since A and B is already sorted, 
        // we can know that A[i] is greater B[j], B[j+1], ..., B[size()-1]
        else 
        {
            C[k++] = B[j++];
            ans += (A.size() - i);
        }
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
 * @return vector<int> as a sorted vector 'v'
 */
vector<int> mergeSort(vector<int> &v, int start, int stop)
{
    // Base case: Has only 1 element, cannot split it further.
    if(start == stop) return {v[start]};

    // Find midpoint of current vector
    int mid = (start + stop)/2;
    // First half of a vector
    vector<int> A = mergeSort(v, start, mid);
    // Second half of a vector
    vector<int> B = mergeSort(v, mid+1, stop);
    // Merged vector
    vector<int> C = merge(A,B);
    // Return sorted vector
    return C;
}

int main()
{
    // This makes std::cin and std::cout faster
    ios_base::sync_with_stdio(false); cin.tie(0);

    // Input
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) { cin >> v[i]; }

    // Merge sort and output
    vector<int> sortedVector = mergeSort(v, 0, v.size() - 1);
    cout << ans;
    return 0;
}