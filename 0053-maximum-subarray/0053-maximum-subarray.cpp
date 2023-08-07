class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int track=0;
        for(auto i=0;i<nums.size();i++)
        {
            track+=nums[i];
            
            if(track>ans)
            {
                ans=track;
            }
            
            if(track<0)
            {
                track=0;
            }
        }
        return ans;
    }
};