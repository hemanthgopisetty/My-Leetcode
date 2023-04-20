class Solution {
public:
    int lcs(vector<vector<int>>&dp,string& a,string& b,int i,int j)
    {
        if(i==0 or j==0)return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(a[i-1]==b[j-1])
        {
           return dp[i][j]=1+lcs(dp,a,b,i-1,j-1);
        }
        
        return dp[i][j]=max(lcs(dp,a,b,i-1,j),lcs(dp,a,b,i,j-1));
    }
    int longestCommonSubsequence(string a, string b) {
        
        int n=a.size();
        int m=b.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return lcs(dp,a,b,n,m);
    }
};