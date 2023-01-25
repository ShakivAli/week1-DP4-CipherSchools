int rainwater(vector<int>&heights)
{
    int n = heights.size();
    vector<int>lmax(n),rmax(n);

    //Initials value
    lmax[0] = heights[0];
    rmax[n-1] = heights[n-1];

    //calculate lmax and rmax
    for(int i=1; i<n; i++)
    {
        lmax[i] = max(heights[i],lmax[i-1]);
    }

    for(int i=n-1; i>1; i--)
    {
        rmax[i] = max(heights[i],rmax[i+1]);
    }

    int water = 0;
    for(int i=1; i<n; i++)
    {
        water += (min(lmax[i],rmax[i]) - heights[i]);
    }
    return water;
}