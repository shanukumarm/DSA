//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        int n = s.length();
        stack<char> st;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == ']')
            {
                string temp = "";
                while(st.top() != '[')
                {
                    temp += st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());
                
                int count=0, t=1;
                while(!st.empty() && int(st.top())>=48 && int(st.top())<=57)
                {
                    count += t*(int(st.top()) - 48);
                    t *= 10;
                    st.pop();
                }
                
                string current = "";
                for(int j=0; j<count; j++)
                    current += temp;
                
                int cur_len = current.length();
                for(int j=0; j<cur_len; j++)
                    st.push(current[j]);
            }
            else
                st.push(s[i]);
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends