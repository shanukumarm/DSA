//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
    int by_changing_array(vector<int>& array, int n)
    {
        bool flag=false;
        
        for(int i=0; i<n-1; i++)
            if(array[i] == n || array[i] == -n)
                flag = true;
            else
            {
                int index = (array[i]>0 ? (array[i]-1) : (-array[i]-1));
                array[index] = array[index]*-1;
            }
        
        if(flag)
            for(int i=0; i<n; i++)
                if(array[i] > 0)
                    return i+1;
                    
        return n;
    }
    
    int sum_n_natural_numbers(vector<int>& array, int n)
    {
        int ans = n*(n+1)/2;
        
        for(int i=0; i<n-1; i++)
        {
            ans -= array[i];
        }
        
        return ans;
    }
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        // return by_changing_array(array, n);
        
        // return sum_n_natural_numbers(array, n);
        
        
        int total = 1;
        for(int i=2; i<=n; i++)
        {
            total += i;
            total -= array[i-2];
        }
        
        return total;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends