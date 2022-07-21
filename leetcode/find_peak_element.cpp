class Solution {
private:
    int findPeak(vector<int> &nums, int low, int high)
    {
        if(high >= low)
        {
            int mid = low + (high-low)/2;
            if(mid == 0)
            {
                if(nums[mid] > nums[mid+1])
                {
                    return mid;
                }
                return findPeak(nums, mid+1, high);
            }
            if(mid == nums.size()-1)
            {
                if(nums[mid] > nums[mid-1])
                {
                    return mid;
                }
                return findPeak(nums, low, mid-1);
            }
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            {
                return mid;
            }
            else if(nums[mid] < nums[mid+1])
            {
                return findPeak(nums, mid+1, high);
            }
            return findPeak(nums, low, mid-1);
        }
        return -1;
    }
    
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        else if(nums.size() == 2)
        {
            if(nums[0] > nums[1])
            {
                return 0;
            }
            return 1;
        }
        return findPeak(nums, 0, nums.size()-1);
    }
};