//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string maxSum(string w,char x[], int b[],int N){
        // code here    
        int startIndex = 0;
        int endIndex = 0;
        int curSIndex = 0;
        // int curEIndex = 0;
        int n = w.length();
        long current_max=0, sum=INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            int current = int(w[i]);
            
            for(int j=0; j<N; j++)
                if(current == int(x[j]))
                {
                    current = b[j];
                    break;
                }
            
            current_max += current;
            
            if(current_max > sum)
            {
                sum = current_max;
                startIndex = curSIndex;
                endIndex = i;
            }
            
            if(current_max < 0)
            {
                current_max = 0;
                curSIndex = i+1;
            }
        }
        
        string ans = "";
        for(int i=startIndex; i<=endIndex; i++)
            ans += w[i];
            
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends