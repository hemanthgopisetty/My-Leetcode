class Solution {
public:
    /*
      We can Hash or sort
        Each element in the nums appears exactly three times except for one element which appers once.
        Observations :-
        1.You must implement a solution with a linear runtime complexity and use only constant extra space.
        2.At any cost , we need to know a element has been visited before.
        3.To write a solution that also follows given follow up,we need to make the element some opertation , so that we can know how many we have been visted a particular element long time ago
        4.One way is to write a function that do some op on that element that gives how many time we vistited this .
        5.Another way is to do some bit manipulation 
        
    */
    int singleNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        if(n==1)return nums[0];
        if(n>1 and nums[0]!=nums[1])return nums[0];
        if(n>1 and nums[n-1]!=nums[n-2])return nums[n-1];
        for(auto i=0;i<n;i+=3)
        {
            if(nums[i]!=nums[i+1])return nums[i];
        }
        return -1;
    }
};