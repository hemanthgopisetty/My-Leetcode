class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int totalSum =accumulate(nums.begin(),nums.end(),0);
        int leftSum =0;
        for(int i=0;i<n;i++){
            totalSum-=nums[i];
             if(totalSum==leftSum)return i;
            leftSum+=nums[i];
        }
        return -1;
    }
};