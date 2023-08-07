class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //2,1,5,4,3,0,0
        
        //Find the break_Pt;
        int n=nums.size();
        
        int breakpt=-1;//assume no breakpt is there
        for(auto i=n-2;i>=0;i--)//find breakpt
        {
            //if curi smaller than the nexti
            if(nums[i]<nums[i+1])//(0,0)X,(3,0)X,(4,3),(5,4)X,(1,5)|/
            {
                breakpt=i;
                break;
            }
        }
        
        if(breakpt==-1)//if no break pt reverse the whole
        {
            reverse(nums.begin(),nums.end());
            return ;
        }
        
        for(auto i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[breakpt])//(0,1)X,(0,1)X,(3,1)|/
            {
                swap(nums[i],nums[breakpt]);//swap => 1,3 ;
                break;
            }
        }
        
        //2,3,5,4,1,0,0
        
        reverse(nums.begin()+breakpt+1,nums.end());
        
        //2,3,0,0,1,4,5
        //next permutation
        return ;
    }
};