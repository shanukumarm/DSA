//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    //easy and simple solution using merge sort
    long long int modified_merge(long long array[], long long left, long long mid, long long right)
    {
        long long count = 0;
        long long leftLimit = mid-left+1, rightLimit = right-mid;
        
        long long *leftArr = new long long[leftLimit], *rightArr = new long long[rightLimit];
        
        for(long long i=0; i<leftLimit; i++)
            leftArr[i] = array[left+i];
        for(long long j=0; j<rightLimit; j++)
            rightArr[j] = array[mid+1+j];
        
        long long indexLeftArray = 0, indexRightArray = 0;
        long long indexMergedArray = left;
        
        while(indexLeftArray<leftLimit && indexRightArray<rightLimit) 
        {
            if(leftArr[indexLeftArray] <= rightArr[indexRightArray]) 
            {
                array[indexMergedArray] = leftArr[indexLeftArray];
                indexLeftArray++;
            }
            else 
            {
                array[indexMergedArray] = rightArr[indexRightArray];
                indexRightArray++;
                count += (leftLimit - indexLeftArray);
            }
            indexMergedArray++;
        }
        
        while (indexLeftArray < leftLimit) 
        {
            array[indexMergedArray] = leftArr[indexLeftArray];
            indexLeftArray++;
            indexMergedArray++;
        }
        
        while (indexRightArray< rightLimit) 
        {
            array[indexMergedArray] = rightArr[indexRightArray];
            indexRightArray++;
            indexMergedArray++;
        }
        delete[] leftArr; delete[] rightArr;
        
        return count;
    }
    
    long long int modified_merge_sort(long long array[], long long left, long long right)
    {
        if(left >= right)
        {
            return 0;
        }
        long long mid = left + (right-left)/2;
        
        return modified_merge_sort(array, left, mid) + modified_merge_sort(array, mid+1, right) + modified_merge(array, left, mid, right);
    }
    
  public:
    // array[]: Input Array
    // N : Size of the Array array[]
    // Function to count inversions in the arrayay.
    long long int inversionCount(long long array[], long long N)
    {
        // Your Code Here
        return modified_merge_sort(array, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends