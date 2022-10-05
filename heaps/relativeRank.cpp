#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int> &score)
{
    priority_queue<pair<int, int>> pq;
    int n = score.size();
    for (int i = 0; i < n; i++)
        pq.push({score[i], i});

    vector<string> res(n);
    int count = 0;

    while (pq.empty() == false)
    {
        count++;
        //* is func mein hum res ke usi index pr rkhege jispr rkhna hoga

        if (count == 1)
            res[pq.top().second] = "Gold Medal";

        else if (count == 2)
            res[pq.top().second] = "Silver Medal";

        else if (count == 3)
            res[pq.top().second] = "Bronze Medal";

        else
            res[pq.top().second] = to_string(count);

        pq.pop();
    }

    return res;
}

int main()
{
    vector<int> score = {5, 4, 3, 2, 1};
    vector<string> res = findRelativeRanks(score);

    for (auto it : res)
        cout << it << " ";
}
