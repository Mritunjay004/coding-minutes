// Expected Time Complexity= O(N log N)
// Find the largest distance from both W and H axis and take their product.

#include <bits/stdc++.h>
using namespace std;

int defkin(int W, int H, vector<pair<int, int>> position)
{
    vector<int> x;
    vector<int> y;

    // as we will make use of i-1 later
    x.push_back(0);
    y.push_back(0);

    for (int i = 0; i < position.size(); i++)
    {
        x.push_back(position[i].first);  // stores the widths
        y.push_back(position[i].second); // stores the  heights
    }

    sort(begin(x), end(x));
    sort(begin(y), end(y));

    int maxx = INT_MIN;
    int maxy = INT_MIN;

    for (int i = 1; i < x.size(); i++)
        maxx = max(maxx, x[i] - x[i - 1] - 1);
    for (int i = 1; i < y.size(); i++)
        maxy = max(maxy, y[i] - y[i - 1] - 1);

    // checking for the last values
    maxx = max(maxx, W - x[x.size() - 1]);
    maxy = max(maxy, H - y[y.size() - 1]);

    return (maxx * maxy);
}

int main()
{
    int W = 15;
    int H = 8;
    vector<pair<int, int>> position = {{3, 8}, {11, 2}, {8, 6}};

    int res = defkin(W, H, position);
    cout << res;
}
