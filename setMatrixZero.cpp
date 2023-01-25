void Solution(vector<vector<int>>&matrix, int r, int c)
{
    vector<int> dummy1(r,-1);            //new linear vector of size row
    vector<int> dummy2(c,-1);            //new linear vector of size column

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(matrix[i][j]==0)             //if any element of a matrix becomes zero
            {
                dummy1[i]=0;             //set the corresponding dummy row and dummy column vectors value to zero
                dummy2[j]=0;
            }
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(dummy1[i]==0 || dummy2[j]==0)               //if any dummy vectors value is zero then we know 
            {                                              //that we have to set the entire elments of the og matrix
                matrix[i][j]=0;                            //to zero whether it is col or row.
            }
        }
    }
}