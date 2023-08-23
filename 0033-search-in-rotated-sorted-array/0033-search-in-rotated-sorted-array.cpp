class Solution {
public:
    int search(vector<int>& nums, int target) {
        //bs 
        //decide how to move l and r
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            //to get rid of overflow l and r INT_MAX
            int mid=l+(r-l)/2;
            if(nums[mid]==target)return mid;
            
            if(nums[l]<=nums[mid])
            {
                //search in this range 
                if(target<=nums[mid] and target>=nums[l])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(target>=nums[mid] and target<=nums[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};