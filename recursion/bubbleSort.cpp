#include <bits/stdc++.h>
using namespace std;

void bubble(int a[], int n, int j)
{
    if (n == 1) //* if one element then the array is sorted
        return;

    if (j == n - 1) //* ek traversal ho gyi
    {
        bubble(a, n - 1, 0);
        return;
    }

    if (a[j] > a[j + 1])
        swap(a[j], a[j + 1]);

    bubble(a, n, j + 1);
}

int main()
{
    int arr[] = {1, 3, 2, 7, 3};
    // int x = 2;
    bubble(arr, 5, 0);
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
}
