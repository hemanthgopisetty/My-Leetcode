class Solution {
public:
    int lps(string&s,int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)return 1;//same character
        
        if(i>j) return 0;
        
        if(dp[i][j])return dp[i][j];
        
        return dp[i][j]= (s[i]==s[j]) ? 2+lps(s,i+1,j-1,dp) :max(lps(s,i+1,j,dp),lps(s,i,j-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        return lps(s,0,n-1,dp);
    }
};