#include <bits/stdc++.h>
using namespace std;

//* given N     M*1 tiles  and M*N Board
//*       5     4*1 tiles and  4*5 board
int tillingProblem(int n, int m)
{
    if (n < m) //* only vertical possible
        return 1;
    int vertical = tillingProblem(n - 1, m);
    int horizontal = tillingProblem(n - m, m);
    return vertical + horizontal;
}

int main()
{
    int res = tillingProblem(4, 4);
    cout << res;
}
