
#include <bits/stdc++.h>
using namespace std;
void _AllParenthesis(string str, int n, int open, int close, vector<string> &result)
{
    if (close == n)
    {
        result.push_back((string)str);
        return;
    }
    else
    {
        if (open > close)
            _AllParenthesis(str + ')', n, open, close + 1, result);
        if (open < n)
            _AllParenthesis(str + '(', n, open + 1, close, result);
    }
}

vector<string> AllParenthesis(int n)
{
    vector<string> result;
    if (n > 0)
        _AllParenthesis("", n, 0, 0, result);
    return result;
}
int main(){

    int n;
    cin >> n;
    vector<string>ans = AllParenthesis(n);
    for(auto i : ans){
        cout << i << " ";
    }

    return 0;
}
