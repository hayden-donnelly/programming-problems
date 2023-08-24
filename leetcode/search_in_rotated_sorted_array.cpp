// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution 
{
public:
    int undo_pivot(int i, int pivot, int size)
    {
        i = i - pivot;
        if(i < 0)
        {
            i = size + i;
        }
        return i;
    }

    int search(vector<int>& nums, int target) 
    {
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        while(l <= r)
        {
            m = l + (r - l) / 2;
            if(nums[m] > nums[r])
            {
                l = m + 1;
            }
            else if(nums[m] < nums[r])
            {
                r = m - 1;
            }
        }

        l = 0;
        r = nums.size()-1;
        int pivot = m;
        int m_offset = 0;
        while(l <= r)
        {
            //r_offset = undo_pivot(r, pivot, nums.size());
            //l_offset = undo_pivot(l, pivot, nums.size());
            m = l + (r - l) / 2;
            m_offset = undo_pivot(m, pivot, nums.size());
            if(nums[m_offset] < target)
            {
                r = m - 1;
            }
            else if(nums[m_offset] > target)
            {
                l = m + 1;
            }
            else
            {
                return m_offset;
            }
        }
        return -1;
    }
};
