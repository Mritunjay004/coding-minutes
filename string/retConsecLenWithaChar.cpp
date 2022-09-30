#include <bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    int counter = 1;
    int n = chars.size();
    string ans = "";

    for (int i = 1; i < n; i++)
    {
        if (chars[i] == chars[i - 1])
            counter++;

        // * adding the char as well as its length to the res
        else if (counter > 1)
        {
            ans += chars[i - 1];
            ans += to_string(counter);
            counter = 1;
        }

        //* if only one character
        else
            ans += chars[i - 1];
    }

    // * for last
    if (counter > 1)
    {
        ans += chars[n - 1];
        ans += to_string(counter);
    }
    return ans.length();
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int res = compress(chars);
    cout << res;
}
