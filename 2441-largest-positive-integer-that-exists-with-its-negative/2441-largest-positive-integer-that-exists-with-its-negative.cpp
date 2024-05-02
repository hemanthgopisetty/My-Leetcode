class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        sort(nums.begin(),nums.end());
        
        while(l<r)
        {
            if(nums[l]+nums[r]==0)
            {
                return nums[r];
            }
            else if(nums[l]+nums[r]<0)
            {
                l++;
            }
            else r--;
        }
        
        return -1;
    }
};