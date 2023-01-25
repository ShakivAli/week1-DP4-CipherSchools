vector <int> spiralMatrix(vector<vector<int>>&mat) {
    int sx=0, sy=0, ex=mat.size()-1, ey=mat[0].size()-1;
    vector<int>result(mat.size()*mat[0].size());
    int counter=0;
    while(sx<=ex && sy<=ey)
    {
        for(int j=sy; j<=ey; j++)
        {
            result[counter] = mat[sx][j];
            counter++;
        }
        sx++;

        for(int j=sx; j<=ex; j++)
        {
            result[counter] = mat[j][ey];
            counter++;
        }
        ey--;

        if(sx <= ex)
        {
            for(int j=ey; j>=sy; j--)
            {
               result[counter] =  mat[ex][j];
               counter++;
            }
            sy--;
        }

        if(sy <= ey)
        {
            for(int j=ex; j>=sx; j--)
            {
               result[counter] = mat[j][sy];
               counter++;
            }
            sy++;
        }
    }
    return result;
}