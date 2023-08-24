// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        while(l <= r)
        {
            m = l + (r - l) / 2;
            if(nums[m] == target)
            {
                return m;
            }
            if(nums[l] <= nums[m])
            {
                // left is sorted
                if(nums[l] <= target && target < nums[m])
                {
                    // target is between l and m
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else
            {
                // right is sorted
                if(nums[r] >= target && target > nums[m])
                {
                    // target is between m and r
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};
