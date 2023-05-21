class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()<2)
        {
            return nums[0];
        }
        vector<int>dp1,dp2;
        dp1.resize(nums.size()+1);
        dp2.resize(nums.size()+1);
        int n=nums.size();
        dp1[0]=0;
        dp1[1]=nums[0];
        dp2[0]=0;
        dp2[1]=0;
        for(auto i=2;i<=nums.size();i++)
        {
            dp1[i]=max(dp1[i-1],nums[i-1]+dp1[i-2]);
            dp2[i]=max(dp2[i-1],nums[i-1]+dp2[i-2]);
        }
        return max(dp1[n-1],dp2[n]);
    }
};