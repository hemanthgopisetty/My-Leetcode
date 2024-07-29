class NumArray {
public:
    vector<int>preSum;
    NumArray(vector<int>& nums) : preSum(nums) {
      for(int i=1;i<nums.size();i++)
      {
          preSum[i]=preSum[i-1]+nums[i];
      }
    }
    
    int sumRange(int left, int right) {
        if(left==0)return preSum[right];
        return preSum[right]-preSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

/*
* create prefixSum 
* Intilaze them during constructor
* Then sum Range will be called then we can return l to r sum in O(1)
*/
