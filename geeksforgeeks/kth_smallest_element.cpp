//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int brute_force(int arr[], int n, int k)
    {
        
        for(int i=0; i<k; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(arr[j] < arr[i])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr[k-1];
    }
    
    int partition (int arr[], int l, int r) 
    { 
        int pivot = arr[r-1];
        int i = l;
      
        for(int j=l; j<r-1; j++) 
        {
            if (arr[j] < pivot) 
            {
                swap(arr[i], arr[j]);
                i++;
            } 
        }
        swap(arr[i], arr[r-1]); 
        return i;
    } 
    
    int modified_quick_sort(int arr[], int l, int r, int k)
    {
        if(l>r)
        {
            return -1;
        }
        
        int p = partition(arr, l, r);
        if(p==k)
        {
            return arr[p];
        }
        else if(p<k)
        {
            return modified_quick_sort(arr, p+1, r, k);
        }
        return modified_quick_sort(arr, l, p, k);
    }
    
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        // return brute_force(arr, r+1, k);
        
        return modified_quick_sort(arr, l, r+1, k-1);
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends