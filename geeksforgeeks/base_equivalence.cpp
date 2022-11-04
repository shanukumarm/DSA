//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string baseEquiv(int n, int m){
        // code here
        for(int i=32; i>=2; i--)
        {
            int temp=i;
            int count=1;
            
            if(i<=n)
            {
                while(temp<=n)
                {
                    temp*=i;
                    count++;
                }
            }
            
            if(count==m)
                return "Yes";
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends