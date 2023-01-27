#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    return (int)pow(x, n);
}
int main()
{
    int x, n;
    cin >> x >> n;

    cout << (power(x, n));
}