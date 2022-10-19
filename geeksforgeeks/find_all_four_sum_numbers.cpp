//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
class Solution{
    
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        int l, r;
        int n = arr.size();
        vector<vector<int>> ans;
        
        qsort(&arr[0], n, sizeof(int), compare);
        
        for(int i=0; i<n-3; i++)
        {
            for(int j=i+1; j<n-2; j++)
            {
                l = j+1;
                r = n-1;
                
                while(l<r)
                {
                    if(arr[i] + arr[j] + arr[l] + arr[r] == k)
                    {
                        ans.push_back({arr[i], arr[j], arr[l], arr[r]});
                        l++;
                        r--;
                        
                        while(l<r && arr[l-1] == arr[l])
                            l++;
                        while(l<r && arr[r+1] == arr[r])
                            r--;
                    }
                    else if(arr[i] + arr[j] + arr[l] + arr[r] < k)
                    {
                        l++;
                        while(l<r && arr[l-1] == arr[l])
                            l++;
                    }
                    else
                    {
                        r--;
                        while(l<r && arr[r+1] == arr[r])
                            r--;
                    }
                }
                while(j+1<n && arr[j+1] == arr[j]) 
                    j++;
            }
            while(i+1<n && arr[i+1] == arr[i])
                i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends