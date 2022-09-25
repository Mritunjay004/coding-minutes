#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> A, int val)
{
    int start = 0;
    int end = A.size() - 1;
    int mid;
    int ans = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (A[mid] > val)
            end = mid - 1;
        else
        {
            ans = A[mid];
            start = mid + 1;
        }
    }
    return ans;
}
