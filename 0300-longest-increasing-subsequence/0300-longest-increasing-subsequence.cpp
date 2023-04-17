class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=INT_MIN;
        vector<int>dp((int)nums.size(),1);
        for(auto i=0;i<nums.size();i++)
        {
            for(auto j=0;j<i;j++)
            {
                if(nums[i] > nums[j] and dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};