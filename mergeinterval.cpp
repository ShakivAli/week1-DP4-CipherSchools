#include <bits/stdc++.h>
using namespace std;
bool mycmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}
vector<vector<int>> merge(vector<vector<int>> &v)
{
    vector<vector<int>> ans;
    sort(v.begin(), v.end(), mycmp); // u can remove mycmp it will still sort it with first element only;
    int n = v.size();
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] <= v[index][1])
        {
            v[index][0] = min(v[index][0], v[i][0]);
            v[index][1] = max(v[index][1], v[i][1]);
        }
        else
        {
            index++;
            v[index][0] = v[i][0];
            v[index][1] = v[i][1];
        }
    }
    for (int i = 0; i <= index; i++)
    {
        ans.push_back(v[i]);
    }
    return ans;
}
int main()
{

    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int first, second;
        cin >> first >> second;
        v[i].push_back(first);
        v[i].push_back(second);
    }
    merge(v); // print answer vector

    return 0;
}