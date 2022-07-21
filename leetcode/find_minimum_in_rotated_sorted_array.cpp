class Solution {
private:
    int midvalue(vector<int> &nums, int low, int high)
    {
        int mid=(high+low)/2;
        if(nums[mid] < nums[0])
        {
            if(nums[mid] < nums[mid-1])
            {
                return nums[mid];
            }
            return midvalue(nums, low, mid-1);
        }
        if(nums[mid] > nums[mid+1])
        {
            return nums[mid+1];
        }
        return midvalue(nums, mid+1, high);
    }
    
public:
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums[nums.size()-1])
        {
            return nums[0];
        }
        if(nums.size() <= 3)
        {
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i] <= nums[nums.size()-1])
                {
                    return nums[i];
                }
            }
            return INT_MIN;
        }
        return midvalue(nums, 0, nums.size()-1);
    }
};