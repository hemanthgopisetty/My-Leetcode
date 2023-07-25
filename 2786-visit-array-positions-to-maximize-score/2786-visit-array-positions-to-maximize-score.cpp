typedef long long ll;
class Solution {
public:
     
    ll fn(vector<int>& nums, int x,int idx,int parity, vector<vector<ll>>&dp)
    {
       //base case 
       if(idx==nums.size())return 0;
       
       /*
         for current index we have choices to include the current element
         in the answer or exclude the current element and go ahead with other element options
         
         exclude the current element in the answer 
         
         if we include in the answer that means current element should have the same parity
         if parity is not same then the element we should remove the x from the answer
       */
       if(dp[idx][parity]!=-1)return dp[idx][parity];
       
       ll pick=INT_MIN,non_pick=INT_MIN;
        
        if(parity==nums[idx]%2)//if parity is same then try this possibility
        {
           pick = nums[idx] + fn(nums,x,idx+1,parity,dp);
        }
       else //not same then try this possibility
       {
           pick  = nums[idx]-x + fn(nums,x,idx+1,nums[idx]%2,dp);
       }
       
      //skip this element and go ahead with other option
       non_pick=fn(nums,x,idx+1,parity,dp);
       
        //store the current element maximum value 
       return dp[idx][parity]=max(pick,non_pick);
    }
    long long maxScore(vector<int>& nums, int x) {
       vector<vector<ll>>dp(nums.size(),vector<ll>(2,-1));
        int parity = nums[0]%2==0 ? 0 : 1 ; 
        return fn(nums,x,0,nums[0]%2,dp);
    }
};