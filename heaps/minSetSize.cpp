
#include <bits/stdc++.h>
using namespace std;

// * You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
// * Return the minimum size of the set so that at least half of the integers of the array are removed.

int minSetSize(vector<int> &arr)
{
    int n = arr.size();
    priority_queue<int> q;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto pair : mp)
    {
        q.push(pair.second);
    }

    int sum = 0;
    int cnt = 0;

    while (n - sum > n / 2) //* n - sum is bec we want lower than or equal to half elements
    {
        sum += q.top(); //* number of occurences for each element
        q.pop();
        cnt++; // * for each element
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 3, 3, 3, 5, 5, 5, 2, 2, 7};
    int res = minSetSize(arr);
}
