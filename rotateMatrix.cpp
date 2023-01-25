void solution(vector<vector<int>>&v, int n)
{
    for(int i=0; i<n; i++)                //transpose of matrix
    {
        for(int j=0; j<i; j++)
        {
            swap(v[i][j],v[j][i]);
        }
    }

    for(int i=0; i<n; i++) 
    {
        reverse(v[i].begin(),v[i].end());       //then reverse every row one by one.
    }
} 