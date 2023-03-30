class Solution {
public:
    /*
    we can write algorithm using divison operator
    that runs in linear time 
    But , given follow up is not to use the divison operator
    So we will use the prefix and posfix array's
    that gives the final output 
    In the division operator using algorithm ,
    we are using the left product and right product in a single variable
    In our follow-up algorithm  use postfix and prefix array's to do the same
    This algorithm takes O(n) time complexity and O(n) space complexity
    To even optimise this we make two passes on the result array
   
   Dry run 
     nums = [1,2,3,4]
      In one pass we will store the prefix here
      prefix=1
      i=0 :
        result[0]=prefix 
        prefix=prefix*nums[0] ->used for next iteration
      i=1 :
        result[1]=prefix
        prefix=prefix*nums[1]->used for next iteration
      .
      .
      .
      .
      upto i=nums.size()-1;
      After this pass the resultant array looks like this
      resut[0...3]=[1,1,2,6] in this way we are using the result array as prefix
      prefix of first two elements like 0..1 results as 3rd element
      
      In the next pass :
        we will traverse from right to left that is from backwards 
      
      postfix=1
      i=nums.size()-1(3):
        result[3]=result[3]*postfix = 6*1 = 6
        postfix=postfix*nums[3] = 1*4 = 4
      .
      .
      .
      .
      i=2:
        result[2]=result[2]*postfix = 2*4 = 8
        postfix= postfix*nums[2] =4*3 = 12 // used for next iteration
      upto i>=0
      then the result array look like this
      resut[0..3]=[24,12,8,6]
      
      Algorithm
      postfix=1,prefix=1
      result[(1)*(0...nums.size())-1]
      forward pass use this to calculate for prefix
      backward pass use this to calculate for postfix
      
      
    */
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1,postfix=1;
        int n=nums.size();
        vector<int>ans(n,1);
        for(auto i=0;i<n;i++)
        {
            ans[i]=prefix;
            prefix=prefix*nums[i];
        }
         for(auto i=n-1;i>=0;i--)
        {
            ans[i]=ans[i]*postfix;
             postfix=postfix*nums[i];
        }
        return ans;
    }
};