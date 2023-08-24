class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return 0;
        if(n==2) return nums[0]>nums[1]?0:1;
        
        int low=1,high=n-2; 
        
        while(low<=high)
        {
            int mid = high+(low-high)/2;
            
            //  prev < middle > next  => peak condition 
            if(nums[mid]>nums[mid-1] and nums[mid]>nums[mid+1]) return mid ;
            //next > mid move to right space solution
            else if(nums[mid+1]>nums[mid]) low = mid+1;
            //prev>mid move to the left space sloution 
            else if(nums[mid-1]>=nums[mid]) high = mid-1;
        }
        
        //check first two element and last two elements 
        
        if(nums[0]>nums[1])return 0;
        else if(nums[n-1]>nums[n-2])return n-1;
        
        return -1 ;
    }
};