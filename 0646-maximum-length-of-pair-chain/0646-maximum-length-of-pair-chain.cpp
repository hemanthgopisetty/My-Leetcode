class Solution {
public:
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>& pairs,int prev,int i)
    {
        if(i>=pairs.size())return 0;
        //pick , dont_t pick
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int pick=0;
        int non_pick=0;
        non_pick=dfs(pairs,prev,i+1);
        if(prev==-1 or pairs[prev][1]<pairs[i][0])pick=1+dfs(pairs,i,i+1);
        return dp[i][prev+1]=max(pick,non_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // cout<<pairs[0][1]<<" "<<pairs[1][0]<<endl;
        dp.resize(pairs.size(),vector<int>(pairs.size()+1,-1));
        sort(begin(pairs),end(pairs));
        return dfs(pairs,-1,0);
    }
};