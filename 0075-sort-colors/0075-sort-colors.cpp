class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,one=0;
        int two=nums.size()-1;
        //zero , one , two represents elements to be updated ;
        while(one<=two)
        {
            int ele = nums[one];
            if(ele==0)
            {
                swap(nums[zero],nums[one]);
                zero++,one++;
            }
            else if(ele==1)
            {
                //represent elements before this all are zeroes 
                one++;
            }
            else //ele == 2
            {
                swap(nums[one],nums[two]);
                two--;
            }
        }
        //ans contains
        //0 to low-1 => o
        //low to mid-1 => 1
        //mid to high 
    }
};