class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        idx=len(nums)-1
        cur_sum=0
        self.memo={}
        return self.dp(nums,target,idx,cur_sum)
    
    def dp(self,nums,target,idx,cur_sum):
        if (idx,cur_sum) in self.memo:
            return self.memo[(idx,cur_sum)]
        
        if idx<0 and cur_sum==target:
            return 1
        
        if idx<0 :
            return 0
        
        positive=self.dp(nums,target,idx-1,cur_sum+nums[idx])
        negative=self.dp(nums,target,idx-1,cur_sum+ -nums[idx])
        
        self.memo[(idx,cur_sum)]=positive+negative
        
        return self.memo[(idx,cur_sum)]