// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);

class Solution {
private:
    int firstBad(long long low, long long high)
    {
        if(low <= high)
        {
            long long mid = (low + high)/2;
            
            bool cur = isBadVersion(mid);
        
            if(cur == true && isBadVersion(mid-1) == false)
            {
                return mid;
            }
            else if(cur == true)
            {
                return firstBad(low, mid-1);
            }
            else
            {
                return firstBad(mid+1, high);
            }
        }
        return -1;
    }
    
public:
    int firstBadVersion(int n) {
        if(n==1)
        {
            return isBadVersion(1);
        }
        return firstBad(1, n);
    }
};