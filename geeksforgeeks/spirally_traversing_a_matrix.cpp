//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    void lr(vector<vector<int>> matrix, vector<int> &ans, int r, int c, int left, int top, int right, int bottom)
    {
        if(left>(c-right-1)) return;
        
        for(int i=left; i<c-right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        tb(matrix, ans, r, c, left, top+1, right, bottom);
    }
    
    void tb(vector<vector<int>> matrix, vector<int> &ans, int r, int c, int left, int top, int right, int bottom)
    {
        if(top>(r-bottom-1)) return;
        
        for(int i=top; i<r-bottom; i++)
        {
            ans.push_back(matrix[i][c-right-1]);
        }
        rl(matrix, ans, r, c, left, top, right+1, bottom);
    }
    
    void rl(vector<vector<int>> matrix, vector<int> &ans, int r, int c, int left, int top, int right, int bottom)
    {
        if(left>(c-right-1)) return;
        for(int i=c-right-1; i>=left; i--)
        {
            ans.push_back(matrix[r-bottom-1][i]);
        }
        bt(matrix, ans, r, c, left, top, right, bottom+1);
    }
    
    void bt(vector<vector<int>> matrix, vector<int> &ans, int r, int c, int left, int top, int right, int bottom)
    {
        if(top>(r-bottom-1)) return;
        for(int i=r-bottom-1; i>=top; i--)
        {
            ans.push_back(matrix[i][left]);
        }
        lr(matrix, ans, r, c, left+1, top, right, bottom);
    }
    
    
    void second_method(vector<vector<int>> matrix, vector<int> &ans, int i, int j, int row, int column)
    {
        if(i>=row || j>=column)
        {
            return;
        }
        
        for(int k=j; k<column; k++)
        {
            ans.push_back(matrix[i][k]);
        }
        for(int k=i+1; k<row; k++)
        {
            ans.push_back(matrix[k][column-1]);
        }
        if(row-1 != i)
        {
            for(int k=column-2; k>=j; k--)
            {
                ans.push_back(matrix[row-1][k]);
            }
        }
        if(column-1 != j)
        {
            for(int k=row-2; k>i; k--)
            {
                ans.push_back(matrix[k][j]);
            }
        }
        
        second_method(matrix, ans, i+1, j+1, row-1, column-1);
    }
    
public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        
        vector<int> ans;
        
        
        // // First method 
        // lr(matrix, ans, r, c, 0, 0, 0, 0);
        
        
        // Second method
        second_method(matrix, ans, 0, 0, r, c);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends