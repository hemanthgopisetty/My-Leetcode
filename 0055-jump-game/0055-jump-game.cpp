class Solution {
public:
    vector<int>dp;
    bool jump(int idx,vector<int>&nums)
    {
        if(idx==nums.size()-1)return true;
        
        if(nums[idx]==0)return false;
        
        if(dp[idx]!=-1)return dp[idx] ;
        
        int cantravel = idx+nums[idx];
        
        for(auto canjump=idx+1; canjump <= cantravel ; canjump++)
        {
            if((canjump < nums.size()) and ( jump(canjump,nums) ) )
            {
                return dp[idx]=true ;
            }
        }
        
        return dp[idx]=false ;
    }
    bool canJump(vector<int>& nums) {
       dp.resize(nums.size(),-1);
        return jump(0,nums);
    }
};