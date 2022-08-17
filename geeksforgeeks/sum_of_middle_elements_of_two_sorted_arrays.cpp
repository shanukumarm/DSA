//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m+n<k || k<1)
        {
            return -1;
        }
        if(n>m)
        {
            return kthElement(arr2, arr1, m, n, k);
        }
        if(n==0)
        {
            return arr2[k-1];
        }
        if(k==1)
        {
            return min(arr1[0], arr2[0]);
        }
        int mid1=min(n, k/2), mid2=min(m,k/2);
        if(arr1[mid1-1] > arr2[mid2-1])
        {
            return kthElement(arr1, arr2+mid2, n, m-mid2, k-mid2);
        }
        return kthElement(arr1+mid1, arr2, n-mid1, m, k-mid1);
    }
public:
    int findMidSum(int ar1[], int ar2[], int n) {
        // code here 
        return kthElement(ar1, ar2, n, n, n) + kthElement(ar1, ar2, n, n, n+1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends