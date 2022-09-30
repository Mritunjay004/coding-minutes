#include <bits/stdc++.h>
using namespace std;

void countSort(vector<int> &arr, int n)
{
    //* finding the largest in the array
    int largest = -1;
    for (int i = 0; i < n; i++)
        largest = max(largest, arr[i]);

    // * making a freq array till the largest and increment as per element
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    // * adding to the array the sorted values
    int j = 0;
    for (int i = 0; i <= largest; i++)
    {
        while (freq[i] > 0)
        {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}

int main()
{
    vector<int> arr = {1, 3, 2};
    // int x = 2;
    countSort(arr, 3);
    for (auto it : arr)
        cout << it << " ";
}
