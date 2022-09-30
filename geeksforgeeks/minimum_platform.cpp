//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    int viaPriorityQueue(int arr[], int dep[], int n)
    {
        vector<pair<int, int>> ad(n);
        
        for(int i=0; i<n; i++)
        {
            ad[i] = { arr[i], dep[i] };
        }
        
        sort(ad.begin(), ad.end());
        
        priority_queue<int, vector<int>, greater<int>> p;
        
        int count=1;
        p.push(ad[0].second);
        
        for(int i=1; i<n; i++)
        {
            if(p.top() >= ad[i].first)
            {
                count++;
            }
            else
            {
                p.pop();
            }
            p.push(ad[i].second);
        }
        return count;
    }
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    // 	return viaPriorityQueue(arr, dep, n);
    
    
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int count=1, ans=0;
    	int i=1, j=0;
    	
    	while(i<n && j<n)   {
    	    if(arr[i] <= dep[j])    {
    	        count++;
    	        i++;
    	    }
    	    else    {
    	        count--;
    	        j++;
    	    }
    	    
    	    if(count>ans)   {
    	        ans=count;
    	    }
    	}
    	
    	return ans;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends