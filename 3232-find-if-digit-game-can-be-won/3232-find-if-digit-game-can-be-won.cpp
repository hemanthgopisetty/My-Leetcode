class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>9)//two digit
            {
                twos+=nums[i];
            }
            else // ones digit
            {
                ones+=nums[i];
            }
        }
        return ones == twos ? false : true ;
    }
};