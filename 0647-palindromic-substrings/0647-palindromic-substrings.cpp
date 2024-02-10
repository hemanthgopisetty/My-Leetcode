class Solution {
public:
    int fn(vector<vector<int>>&dp,string& s,int i,int j)
    {
        if(i>=j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = s[i]==s[j] ? fn(dp,s,i+1,j-1) : 0 ;
    }
    int countSubstrings(string s) {
        
        int count=0,n=s.size();
        
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
            {
                count += fn(dp,s,i,j);
            }
        }
        
        return count;
    }
};