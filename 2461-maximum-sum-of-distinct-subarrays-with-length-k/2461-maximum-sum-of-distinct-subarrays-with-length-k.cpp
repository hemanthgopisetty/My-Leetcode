class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        //fixed size
       long long sum=0;
        map<long long,long long> seen;
        long long ans=0;
        
        
        for(auto i=0;i<k;i++)
        {
            seen[nums[i]]++;
            sum+=nums[i];
        }
        
        if(seen.size()==k)ans=sum;
        
        for(auto i=k;i<nums.size();i++)
        {
           seen[nums[i]]++;
           seen[nums[i-k]]--;
           
           if(seen[nums[i-k]] == 0)seen.erase(nums[i-k]);
            
            sum+=nums[i];
            sum-=nums[i-k];
            
            if(seen.size()==k)ans=max(ans,sum);
        }
        
        return ans;
    }
};