//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
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