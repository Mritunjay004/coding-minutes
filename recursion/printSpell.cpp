#include <bits/stdc++.h>
using namespace std;

string spell[] = {"zero", "one", "two", "three", "four"}; //*just for prac i am taking till 4

//* 2021
void printSpells(int n)
{
    if (n == 0)
        return;
    int lastDigit = n % 10; //* 1

    printSpells(n / 10); // * 202
    cout << spell[lastDigit] << " ";
}

int main()
{
    printSpells(2021);
}
