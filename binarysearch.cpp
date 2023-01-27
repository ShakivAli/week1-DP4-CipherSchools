#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &v, int n, int key)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}

int main()
{

    int n, key;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> key;
    cout << binarySearch(v, n, key) << endl;
    return 0;
}