class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        int dp[1001][1001]{};
        for(auto i=1;i<m+1;i++)
        {
            for(auto j=1;j<n+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
        
    }
};