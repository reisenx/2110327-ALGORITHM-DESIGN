#include<iostream>
#include<vector>
using namespace std;

void heapSort(vector<int> &v)
{
    for(int root = (v.size()/2) - 1; root >= 0; root--)
        fixHeap(v, root);
    
    for(int i = v.size() - 1; i >= 0; i--)
    {
        swap(v[0],v[i]);
        fixHeap(v, 0);
    }
}

void fixHeap(vector<int> &v, int root)
{
    int newRoot = root;
    int leftChild = (2*root) + 1;
    int rightChild = (2*root) + 2;
    
    if(leftChild < v.size() && v[leftChild] > v[newRoot])
        newRoot = leftChild;
    if(rightChild < v.size() && v[rightChild] > v[newRoot])
        newRoot = rightChild;
    
    if(newRoot != root)
    {
        swap(v[root], v[newRoot]);
        fixHeap(v, newRoot);
    }
}

int main()
{
    
}