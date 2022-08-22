//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    int ans=0;
	    pair<int, int> temp[n];
	    vector<bool> visited(n, false);
	    
	    for(int i=0; i<n; i++)
	    {
	        temp[i].first = nums[i];
	        temp[i].second = i;
	    }
	    
	    sort(temp, temp+n);
	    
	    for(int i=0; i<n; i++)
	    {
	        if(visited[i] || temp[i].second == i)
	            continue;
	        
	        int j=i;
	        
	        while(!visited[j])
	        {
	            ans++;
	            visited[j] = true;
	            
	            j = temp[j].second;
	        }
	        
	        ans--;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends