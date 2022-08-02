//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    struct queueEntry
    {
        int vertex;
        int distance;
    };
    
    int minThrowBFS(vector<int> moves, int n)
    {
        vector<bool> visited(n, false);
        visited[0] = true;
        
        queue<queueEntry> q;
        q.push({0, 0});
        
        queueEntry qe;
        while(!q.empty())
        {
            qe = q.front();
            
            int v = qe.vertex;
            if(v == n-1) break;
            
            q.pop();
            for(int i=v+1; i<=(v+6) && i<n; i++)
            {
                if(!visited[i])
                {
                    queueEntry a;
                    a.distance = qe.distance+1;
                    
                    visited[i] = true;
                    
                    a.vertex = (moves[i] != -1 ? moves[i] : i);
                    q.push(a);
                }
            }
        }
        return qe.distance;
    }
    
public:
    int minThrow(int N, int arr[]){
        // code here
        int n=30;
        
        vector<int> moves(30, -1);
        
        for(int i=0; i<N; i++)
        {
            moves[arr[i*2] - 1] = arr[i*2+1] - 1;
        }
        
        return minThrowBFS(moves, n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends