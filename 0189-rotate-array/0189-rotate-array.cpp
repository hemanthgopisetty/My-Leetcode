class Solution {
public:
    void reverse(vector<int>&nums,int l,int r)
    {
        while(l<r)
        {
            swap(nums[l],nums[r]);
            l++,r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        if( k < 0 )k += len;
        reverse(nums,0,len-k-1);
        reverse(nums,len-k,len-1);
        reverse(nums,0,len-1);
    }
};