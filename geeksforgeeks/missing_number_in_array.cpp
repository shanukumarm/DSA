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
    
    int xor_(vector<int>& array, int n) 
    {
        int a=0, b=0;
        
        for(int i=0; i<n-1; i++)
        {
            a = a^array[i];
        }
        for(int i=1; i<=n; i++)
        {
            b = b^i;
        }
        return a^b;
    }
    
    int cyclic_sort(vector<int>& array, int n) 
    {
        int i=0;
        while(i<n)
        {
            int correct = array[i]-1;
            if(array[i] < n && array[i] != array[correct])
                swap(array[i], array[correct]);
            else
                i++;
        }
        
        for(int i=0; i<n; i++)
            if(i != array[i]-1)
                return i+1;
                
        return n;
    }
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        // return by_changing_array(array, n);
        
        // return sum_n_natural_numbers(array, n);
        
        // // XOR as a comparison operator sumof(x) ^ sumof(y) = 0, if sumof(x) and sumof(y) are equal.
        // return xor_(array, n);
        
        // // cyclic sort method
        // return cyclic_sort(array, n);
        
        
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