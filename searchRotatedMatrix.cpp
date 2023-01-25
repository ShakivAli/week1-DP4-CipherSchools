int search(vector<int>&nums, int start, int end, int target)
{
    if(start>end) return -1;
    int mid = start+(end-start)/2;
    if(nums[mid] == target) return mid;

    //1st section sorted or second
    if(nums[start] <= nums[mid])
    {
        //1st section is sorted
        if(nums[start] <= target && target <= nums[end]) {
            return search(nums,start,mid-1,target);
        }
        else
        {
            return search(nums,mid+1,end,target);
        }
    }
    else
    {
        //2nd section is sorted
        if(nums[mid] <= target && target <= nums[end]) {
            return search(nums,mid+1,end,target);
        }
        else
        {
            return search(nums,start,mid-1,target);
        }
    }
}