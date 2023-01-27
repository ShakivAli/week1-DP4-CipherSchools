// CPP program to generate power set
#include <bits/stdc++.h>
using namespace std;

void powerSet(string str, int index = 0, string curr = "")
{
    int n = str.length();

    // base case
    if (index == n)
    {
        cout << curr << endl;
        return;
    }
    powerSet(str, index + 1, curr + str[index]);
    powerSet(str, index + 1, curr);
}

int main()
{
    string str;
    cin >> str;
    powerSet(str);
    return 0;
}
