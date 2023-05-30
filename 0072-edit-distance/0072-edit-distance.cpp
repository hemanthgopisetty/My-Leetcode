class Solution {
public:
    //Easy Dynamic Programming => dfs+memo
    int dfs(string& s1,string& s2,int m,int n,vector<vector<int>>&dp)
    {
        if(m==0)return dp[m][n]=n;
        if(n==0)return dp[m][n]=m;
        
        if(dp[m][n]!=-1)return dp[m][n];
            
        if(s1[m-1]==s2[n-1])
        {
           return dp[m][n]=dfs(s1,s2,m-1,n-1,dp);
        }
        
            //we have 3 opt
            int ins =   dfs(s1,s2,m,n-1,dp);
            int del =   dfs(s1,s2,m-1,n,dp);
            int rep =   dfs(s1,s2,m-1,n-1,dp);
            
            return dp[m][n]=1+min({ins,del,rep});
      
    }
    int minDistance(string word1, string word2) {
        int n=word2.size();
        int m=word1.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        /*
            We do that for not to access the indexes negatively in any chance
            when there is a call for 1,1 then it will check for 0,0
            when there is a call for 0,0 that means we need to insert those no of characters over there
            
        */
        return dfs(word1,word2,m,n,dp);
    }
};