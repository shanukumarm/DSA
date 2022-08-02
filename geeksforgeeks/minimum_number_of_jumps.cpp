//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int i=0, count=0;
        while(i<n-1)
        {
            count++;
            if(arr[i] == 0)
            {
                return -1;
            }
            if((i+arr[i]) >= n-1)
            {
                return count;
            }
            
            int cur_max = i+arr[i], temp=i;
            for(int j=i+1; j<=(i+arr[i]); j++)
            {
                if((j+arr[j]) > cur_max)
                {
                    cur_max = j+arr[j];
                    temp = j;
                }
            }
            if(cur_max==(i+arr[i]))
            {
                return -1;
            }
            i=temp;
        }
        return count;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends