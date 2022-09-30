//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    int potential_majority_finder(int a[], int size)
    {
        int majority_index = 0, count = 1;
        for(int i=1; i<size; i++)
        {
            if(a[majority_index] == a[i])
                count++;
            else
                count--;
            if(count == 0)
            {
                majority_index = i;
                count = 1;
            }
        }
        return a[majority_index];
    }
    
    int majority_assurrer(int a[], int size, int potential_majority)
    {
        int count = 0;
        for(int i=0; i<size; i++)
        {
            if(a[i] == potential_majority)
                count++;
        }
        
        if(count > size/2)
            return potential_majority;
        return -1;
    }
    
 public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        // your code here
        int potential_majority = potential_majority_finder(a, size);
        
        return majority_assurrer(a, size, potential_majority);
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends