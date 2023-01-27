#include <bits/stdc++.h>
using namespace std;
bool triplet(vector<int> &v, int target)
{
    int n = v.size();
    sort(v.begin(), v.end()); // in the case array input is not sorted;
    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1, end = n - 1, sum = target - v[i];
        while (start < end)
        {
            if (v[start] + v[end] == sum)
            {
                return true;
            }
            else if (v[start] + v[end] < sum)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    return false;
}
int main()
{

    int n, target;
    cin >> n >> target;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << triplet(v, target) << endl;

    return 0;
}