//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    int isSafe(vector<vector<int>> &planet, int row, int col, vector<vector<int>> &visited)
    {
        int rows = planet.size();
        int columns = planet[0].size();
        
        return (row>=0 && row<rows && col>=0 && col<columns && 
                planet[row][col] && !visited[row][col]);
    }
    
    void dfs(vector<vector<int>> &planet, int i, int j, vector<vector<int>> &visited)
    {
        static int rowNum[] = {0, 0, -1, 1};
        static int colNum[] = {-1, 1, 0, 0};
        
        visited[i][j] = true;
        
        for(int k=0; k<4; k++)
        {
            if(isSafe(planet, i + rowNum[k], j + colNum[k], visited))
            {
                dfs(planet, i + rowNum[k], j + colNum[k], visited);
            }
        }
    }
    
    vector<int> brute_force_dfs(int n, int m, vector<vector<int>> &operators) {
        int k = operators.size();
        vector<int> ans(k, 0);
        vector<vector<int>> planet(n, vector<int> (m, 0));
        
        for(int i=0; i<k; i++)
        {
            int row = operators[i][0];
            int column = operators[i][1];
            
            planet[row][column] = 1;
            
            if(i==0)
            {
                ans[i] = 1;
                continue;
            }
            
            vector<vector<int>> visited(n, vector<int> (m, 0));
            
            for(int a=0; a<n; a++)
            {
                for(int b=0; b<m; b++)
                {
                    if(planet[a][b] && !visited[a][b])
                    {
                        dfs(planet, a, b, visited);
                        
                        ans[i]++;
                    }
                }
            }
        }
        return ans;
    }
    
    int p[100000];
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int index(int x, int y, int m)
    {
        return x * m + y;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        // return brute_force_dfs(n, m, operators);
        
        // Creator's solution
        if (operators.empty())
            return {};

        vector<int> res;
        unordered_set<int> nodes;
        unordered_set<int> current;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int total = 0;
        
        for(auto op : operators)
        {
            int pos = index(op[0], op[1], m);
            nodes.insert(pos);
            if(current.count(pos))
            {
                res.push_back(total);
                continue;
            }
            total++;
            p[pos] = pos;
            for (int j = 0; j < 4; j++)
            {
                int nx = op[0] + dx[j];
                int ny = op[1] + dy[j];
                if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) 
                    continue;
                if (current.count(index(nx, ny, m)))
                {
                    int apos = index(op[0], op[1], m);
                    int bpos = index(nx, ny, m);
                    if (find(apos) != find(bpos))
                    {
                        p[find(apos)] = find(bpos);
                        total--;
                    }
                }
            }

            current.insert(index(op[0], op[1], m));
            res.push_back(total);
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends