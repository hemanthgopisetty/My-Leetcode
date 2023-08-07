class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //Find the break_Pt;
        int n=nums.size();
        
        int breakpt=-1;//assume no breakpt is there
        for(auto i=n-2;i>=0;i--)//find breakpt
        {
            //if curi smaller than the nexti
            if(nums[i]<nums[i+1])
            {
                breakpt=i;
                break;
            }
        }
        
        if(breakpt==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(auto i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[breakpt])
            {
                swap(nums[i],nums[breakpt]);
                break;
            }
        }
        
        reverse(nums.begin()+breakpt+1,nums.end());
        return ;
    }
};