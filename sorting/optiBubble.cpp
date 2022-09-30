#include <bits/stdc++.h>
using namespace std;

vector<int> optimizedBubbleSort(vector<int> v)
{
    // your code  goes here
    vector<int> res = v;
    int n = v.size();
    bool swapped;

    for (int times = 1; times < n; times++) //* times will tell how much times we have to do work for all elements
    {
        swapped = false;
        for (int j = 0; j < n - times; j++) // * j will move from each till end
        {
            if (res[j] > res[j + 1])
            {
                swap(res[j], res[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) // * no need to do work if the array is sorted
            break;
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 3, 2};
    // int x = 2;
    vector<int> res = optimizedBubbleSort(arr);
    for (auto it : res)
        cout << it << " ";
}
