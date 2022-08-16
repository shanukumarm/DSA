//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    // int find(int arr1[], int arr2[], int left1, int right1, int left2, int right2, int k)
    // {
    //     if(left1 > right1)
    //     {
    //         return arr2[k-left1];
    //     }
    //     if(left2 > right2)
    //     {
    //         return arr1[k-left2];
    //     }
    //     int mid1 = left1 + (right1-left1)/2;
    //     int mid2 = left2 + (right2-left2)/2;
    //     if(mid1+mid2 < k)
    //     {
    //         if(arr1[mid1] > arr2[mid2])
    //         {
    //             return find(arr1, arr2, left1, right1, mid2+1, right2, k);
    //         }
    //         return find(arr1, arr2, mid1+1, right1, left2, right2, k);
    //     }
    //     if(arr1[mid1] > arr2[mid2])
    //     {
    //         return find(arr1, arr2, left1, mid1-1, left2, right2, k);
    //     }
    //     return find(arr1, arr2, left1, right1, left2, mid2-1, k);
    // }
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        // return find(arr1, arr2, 0, n-1, 0, m-1, k-1);
        
        
        if(n+m<k || k<1)
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
        
        int mid1 = min(n, k/2), mid2 = min(m, k/2);
        
        if(arr1[mid1-1] > arr2[mid2-1])
        {
            return kthElement(arr1, arr2+mid2, n, m-mid2, k-mid2);
        }
        return kthElement(arr1+mid1, arr2, n-mid1, m, k-mid1);
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends