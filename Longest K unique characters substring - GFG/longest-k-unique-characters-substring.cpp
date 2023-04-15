//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    
    int l=0,r=0;    
    int ans=-1;    
    map<char,int>seen;
    
    
    while(r< s.size())
    {
        seen[s[r]]++;
        
        //this loops runs from l
        while(seen.size() > k)
        {
            seen[s[l]]--;
            if(seen[s[l]]==0)
            {
                seen.erase(s[l]);
            }
            l++;
        }
        
        if(seen.size()==k)
        {
            ans=max(ans,r-l+1);
        }
        
        r++;
    }
      
      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends