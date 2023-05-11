class Solution {
public:
    int lcs(vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp,int i,int j)
    {
        if(i==nums1.size() or j==nums2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(nums1[i]==nums2[j])
        {
            return dp[i][j]=1+lcs(nums1,nums2,dp,i+1,j+1);
        }
        else
        {
            return dp[i][j]=max(lcs(nums1,nums2,dp,i+1,j),lcs(nums1,nums2,dp,i,j+1));
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //LCS bro
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return lcs(nums1,nums2,dp,0,0);
    }
};