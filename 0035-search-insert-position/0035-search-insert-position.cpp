class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};

/*

1,3,5,6 5
0 1 2 3 2

l=0,h=3
m=l+(h-l)/2=>0+1=1
move low to right

l=m+1=2,h=3
m=2+0=2
target equal return mid



*/