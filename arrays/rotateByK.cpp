#include <bits/stdc++.h>
using namespace std;

vector<int> kRotate(vector<int> a, int k)
{
    vector<int> v;
    int n = a.size();
    k = k % n;

    for (int i = 0; i < n; i++)
    {
        if (i < k)
        {
            v.push_back(a[n + i - k]); //* putting the elements that needs to be rotated
        }
        else
        {
            v.push_back(a[i - k]); //*putting the still elements
        }
    }
    return v;
}

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    int x = 2;
    vector<int> res = kRotate(arr, x);
}
