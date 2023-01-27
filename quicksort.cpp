#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int low, int high)
{
    int i = low - 1, j = high + 1, pivot = v[low];
    while (true)
    {
        do
        {
            i++;
        } while (v[i] < pivot);
        do
        {
            j--;
        } while (v[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swap(v[i], v[j]);
    }
}
void qsort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int p = partition(v, low, high);
        qsort(v, low, p);
        qsort(v, p + 1, high);
    }
}
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int low = 0, high = n - 1;
    qsort(v, low, high);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}