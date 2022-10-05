#include <bits/stdc++.h>
using namespace std;

//* if n is even we can return for a^n = (a^n/2)^2
//* else we can return a^n = a(a^n/2)^2
int Power(int a, int n)
{
    if (n == 0)
        return 1;

    int subProb = Power(a, n / 2);
    int num = subProb * subProb;
    if (n % 2 == 0)
        return num;
    else
        return a * num;
}

int main()
{
    int ans = Power(5, 2);
    cout << ans;
}
