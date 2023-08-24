class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1) return  0;
        if(n==2)  return nums[0]>nums[1] ? 0 : 1;
        
        //leave the first and last element 
        int low = 1,high=n-2 ;
        
        while(low<=high)
        {
            //calculate the mid 
            int mid = high + (low-high)/2;
            
            //check wether mid is peak or not
            if( (nums[mid]>nums[mid-1])  and (nums[mid]>nums[mid+1]) )
            {
                return mid ;
            }
            else if(nums[mid+1]>nums[mid])
            {
                low = mid+1;
            }
            else if(nums[mid-1]>=nums[mid])
            {
                high = mid-1;
            }
        }
        
        if(nums[0]>nums[1])
        {
            return 0;
        }
        else if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        
        return -1;
    }
};