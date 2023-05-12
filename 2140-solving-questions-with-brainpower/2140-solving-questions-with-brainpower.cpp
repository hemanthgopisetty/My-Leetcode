class Solution {
public:
    long long solve(vector<long long>&dp,vector<vector<int>>&a,int idx)
    {
        if(idx>=a.size())
        {
            return 0;
        }
        
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        
        //One function call's create two functions call on array index's
        long long take_it = a[idx][0]+solve(dp,a,idx+a[idx][1]+1);
        
        long long leave_it = solve(dp,a,idx+1);

        return dp[idx]=max(take_it,leave_it);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long n=questions.size();
        vector<long long>dp(n+1,-1);
        return solve(dp,questions,0);
    }
};