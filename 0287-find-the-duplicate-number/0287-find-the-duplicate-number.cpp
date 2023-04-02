class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slow=0,fast=0;
       while(true)
       {
           slow=nums[slow];
           fast=nums[nums[fast]];
            if(slow==fast)
            {
                int slow2=0,duplicate;
                while(true)
                {
                    slow=nums[slow];
                    slow2=nums[slow2];
                    if(slow==slow2)
                    {
                        duplicate=slow2;
                        return duplicate;
                    }
                }
            }
       }
      
       return 0;
    }
};