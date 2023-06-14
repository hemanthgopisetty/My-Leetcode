class Solution {
public:
    int dp[20001];
    int dfs(vector<int>&nums,int idx)
    {
        if(idx>=nums.size())
        {
            return 0;
        }
        
        if(dp[idx]!=-1)return dp[idx];
        int curVal=nums[idx];
        int curSum =nums[idx];
        int index  =idx+1;
        
        //add all same elements
        while(index<nums.size() and nums[index]==curVal)
        {
            curSum+=nums[idx];
            index++;
        }
        
        //skip all the elements whose val is equal to the curVal+1
        while(index<nums.size() and nums[index]==curVal+1)
        {
            index++;
        }
        
        //we have two choices wether to include our sum
        //or exclude it ,we explore all the possibilites 
        //and take max of them
        
        //max(pick,nonPick)
        //Pick the elements with all of the frequencies of curval and move the index to the 
        //curVal+1
        
        return dp[idx]=max(curSum+dfs(nums,index),dfs(nums,idx+1));
    }
    int deleteAndEarn(vector<int>& nums) {
        // sort the array to get rid of all arr[i] - 1 elements
        sort(begin(nums),end(nums));
        memset(dp,-1,sizeof(dp));
        return dfs(nums,0);
    }
};