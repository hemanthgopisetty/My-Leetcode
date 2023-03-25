class Solution {
public:
    int fib(int n) {
        
        if(n<=1)return n;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        cout<<dp.size();
        for(auto i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
            cout<<dp[i]<<"-"<<i<<endl;
        }
        return dp[n];
    }
};