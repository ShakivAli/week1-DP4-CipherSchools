#include <bits/stdc++.h>
using namespace std;
vector<string> ans;

void words(vector<int>&a, string res, int j, int n, unordered_map<int, string> &map1)
{
    if (res.length() == n)
    {
        if (res != "")
            ans.push_back(res);
        return;
    }

    for (int i = 0; i < map1[a[j]].length(); i++)
    {
        words(a, res + map1[a[j]][i], j + 1, n, map1);
    }
}
// Function to find list of all words possible by pressing given numbers.
vector<string> possibleWords(vector<int>& a, int N)
{
    unordered_map<int, string> map1;
    map1.insert({0, ""});
    map1.insert({1, ""});
    map1.insert({2, "abc"});
    map1.insert({3, "def"});
    map1.insert({4, "ghi"});
    map1.insert({5, "jkl"});
    map1.insert({6, "mno"});
    map1.insert({7, "pqrs"});
    map1.insert({8, "tuv"});
    map1.insert({9, "wxyz"});
    words(a, "", 0, N, map1);
    sort(ans.begin(), ans.end());
    return ans;
}
int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<string>ans = possibleWords(arr, n);
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}