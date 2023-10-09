class Solution {
public:
    int lower(vector<int>&nums,int target)
    {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid = (r-l)/2+l;
            
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower(nums,target);
        int r = lower(nums,target+1)-1;
        
        if(l<nums.size() and nums[l]==target)
        {
            return {l,r};
        }
        else return {-1,-1};
    }
};