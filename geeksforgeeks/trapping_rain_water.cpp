//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        // int lr[n], rl[n];
        // lr[0] = arr[0], rl[n-1] = arr[n-1];
        // for(int i=1; i<n; i++)
        // {
        //     lr[i] = max(lr[i-1], arr[i]);
        //     rl[n-i-1] = max(rl[n-i], arr[n-i-1]);
        // }
        
        // long long sum=0;
        // for(int i=0; i<n; i++)
        // {
        //     sum += min(lr[i], rl[i]) - arr[i];
        // }
        // return sum;
        
        
        int left=0, right=n-1;
        long long sum=0;
        int leftMax=0, rightMax=0;
        
        while(left<=right)
        {
            if(arr[left]<=arr[right])
            {
                if(arr[left]>=leftMax)
                    leftMax=arr[left];
                else
                    sum += leftMax-arr[left];
                left++;
                continue;
            }
            if(arr[right]>=rightMax)
                rightMax=arr[right];
            else
                sum += rightMax-arr[right];
            right--;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends