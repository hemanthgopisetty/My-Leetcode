class Solution {
public:
    vector<int> dp;
    Solution()
    {
        vector<int>a(31,-1);
        dp=a;
    }
    int fib(int n) {
        /*****************************************
        //Bottom up ->base case to desried case *
        // if(n<=1)return n;                    *    
        // vector<int> dp(n+1,0);               *
        // dp[0]=0;                             *
        // dp[1]=1;                             *
        // cout<<dp.size();                     *
        // for(auto i=2;i<=n;i++)               *
        // {                                    *
        //     dp[i]=dp[i-1]+dp[i-2];           *
        //     cout<<dp[i]<<"-"<<i<<endl;       *
        // }                                    *
        // return dp[n];                        *
        /****************************************/
        if(n<=1)return n;
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return fib(n-1)+fib(n-2);
    }
};