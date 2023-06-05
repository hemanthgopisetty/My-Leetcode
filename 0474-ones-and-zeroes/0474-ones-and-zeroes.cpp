class Solution {
public:
    int countz(string &str)
    {
        int cnt = 0;
        for(auto &it : str)
        {
            if(it == '0')
                cnt++;
        }
        return cnt;
    }
    int counto(string &str)
    {
        int cnt = 0;
        for(auto &it : str)
        {
            if(it == '1')
                cnt++;
        }
        return cnt;
    }
    int dfs(vector<string>& strs, int m, int n,int idx,vector<vector<vector<int>>>&dp)
    {
        if(idx>=strs.size())
        {
            return 0;
        }
        //we have found one way 
        // if(m==0 or n==0)
        // {
        //     return 1;
        // }
        if(dp[idx][m][n]!=-1)
        {
            return dp[idx][m][n];
        }
        int cnt0=countz(strs[idx]);
        int cnt1=counto(strs[idx]);
        
        //pick
        int pick=INT_MIN;
        
        if(m>=cnt0 and n>=cnt1)
        {
            pick = 1+dfs(strs,m-cnt0,n-cnt1,idx+1,dp);
        }
        //nonpick
        int nonpick=0+dfs(strs,m,n,idx+1,dp);
        return dp[idx][m][n]=max(pick,nonpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        //It's 3d matrix because the state depends on idx,m,n
        vector<vector<vector<int>>>dp(s+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return dfs(strs,m,n,0,dp);
    }
};