#include <bits/stdc++.h>
using namespace std;

long swapCount(string chars)
{

    int countLeft = 0, countRight = 0;
    int swap = 0, imbalance = 0;

    for (int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == '[')
        {

            countLeft++;

            if (imbalance > 0)
            {
                swap += imbalance;
                imbalance--;
            }
        }
        else if (chars[i] == ']')
        {
            countRight++;
            imbalance = (countRight - countLeft);
        }
    }
    return swap;
}
int main()
{
    string s;
    cin >> s;
    cout << swapCount(s) << endl;

    return 0;
}
