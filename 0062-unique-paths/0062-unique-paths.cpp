class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        dp[0][0]=1;
        for(auto i=1;i<n;i++)
        {
           dp[0][i]=1;
        }
        for(auto j=1;j<m;j++)
         {
            dp[j][0]=1;
         }
        for(auto i=1;i<m;i++){
            for (auto j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
         }
        return dp[m-1][n-1];
    }
};