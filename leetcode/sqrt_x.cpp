class Solution {
private:
    int findvalue(long long x, long long low, long long high)
    {
        long long mid=(high+low)/2;
        if(mid*mid == x || low == mid)
        {
            return mid;
        }
        else if(mid*mid > x)
        {
            return findvalue(x, low, mid);
        }
        return findvalue(x, mid, high);
    }
    
public:
    int mySqrt(int x) {
        if(x==0)
        {
            return 0;
        }
        int low=1, high=x;
        return findvalue(x, low, high);
    }
};