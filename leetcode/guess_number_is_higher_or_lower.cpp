/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
private:
    int guessednumber(long long low, long long high)
    {
        long long mid=(low+high)/2;
        
        if(guess(mid) == 0)
        {
            return mid;
        }
        else if(guess(mid) == 1)
        {
            return guessednumber(mid+1, high);
        }
        return guessednumber(low, mid-1);
    }
    
public:
    int guessNumber(int n) {
        return guessednumber(1, n);
    }
};