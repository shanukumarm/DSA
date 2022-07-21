class Solution {
private:
    int binarysearch(vector<int> &nums, int target, int low, int high)
    {
        if(high >= low)
        {
            int mid=low+(high-low)/2;

            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                return binarysearch(nums, target, low, mid-1);
            }
            else
            {
                return binarysearch(nums, target, mid+1, high);
            }
        }
        else
        {
            return -1;
        }
    }
    
    int midvalue(vector<int> &nums, int low, int high)
    {
        int mid=(high+low)/2;
        
        if(nums[mid] < nums[0])
        {
            if(nums[mid] < nums[mid-1])
            {
                return mid;
            }
            else
            {
                return midvalue(nums, low, mid-1);
            }
        } 
        else
        {
            if(nums[mid] > nums[mid+1])
            {
                return mid+1;
            }
            else
            {
                return midvalue(nums, mid+1, high);
            }
        }
    }
    
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() <= 3)
        {
            for(int i=0; i<nums.size(); i++)
            {
                if(nums[i] == target)
                {
                    return i;
                }
            }
            return -1;
        }
        if(nums[0] < nums[nums.size()-1])
        {
            return binarysearch(nums, target, 0, nums.size()-1);
        }
        int mid = midvalue(nums, 0, nums.size()-1);
        
        
        //Binary search
        
        if(nums[0] <= target)
        {
            return binarysearch(nums, target, 0, mid-1);
        }
        else
        {
            return binarysearch(nums, target, mid, nums.size()-1);
        }
        return 0;
    }
};