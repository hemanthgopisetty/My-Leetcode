class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans ;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            //if visited mark it as visited
            //mark it as negative number
            
            //if it's negative then we visted it already 
            //else mark it negative
            
            if(nums[abs(nums[i])-1]<0)
            {
                ans.push_back(abs(nums[i]));
            }
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1] ;
        }
        return ans ;
    }
};