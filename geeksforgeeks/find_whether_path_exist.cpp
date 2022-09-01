//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    bool isSafe(int i, int j, int n)
    {
        if(i<n && j<n && i>=0 && j>=0)
            return true;
        return false;
    }
    
    bool isPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited)
    {
        int n=grid.size();
        if(isSafe(i, j, n) && grid[i][j] != 0 && visited[i][j] == 0)
        {
            visited[i][j] = true;
            
            if(grid[i][j] == 2)
                return true;
            
            return (isPath(grid, i-1, j, visited) || isPath(grid, i, j-1, visited) ||
                         isPath(grid, i+1, j, visited) || isPath(grid, i, j+1, visited));
        }
    }
public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        // bool flag=false;
        vector<vector<int>> visited(n, vector<int> (n, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    return isPath(grid, i, j, visited);
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends