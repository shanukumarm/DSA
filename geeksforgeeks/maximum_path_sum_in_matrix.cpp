//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int usingForLoop(int n, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        // Last line copied as it is
        for(int i=0; i<n; i++)
        {
            dp[n-1][i] = Matrix[n-1][i];
        }
        
        // max path sum from bottom to up
        for(int i=n-2; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                if(j==0)
                {
                    dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + Matrix[i][j];
                }
                else if(j==n-1)
                {
                    dp[i][j] = max(dp[i+1][j-1], dp[i+1][j]) + Matrix[i][j];
                }
                else
                {
                    dp[i][j] = max(max(dp[i+1][j-1], dp[i+1][j]), dp[i+1][j+1]) + Matrix[i][j];
                }
            }
        }
        
        // Solution from first row of DP matrix
        int maxDistance = INT_MIN;
        for(int i=0; i<n; i++)
        {
            maxDistance = max(maxDistance, dp[0][i]);
        }
        
        return maxDistance;
    }
    
public:
    int maximumPath(int n, vector<vector<int>> Matrix)
    {
        // code here
        return usingForLoop(n, Matrix);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends