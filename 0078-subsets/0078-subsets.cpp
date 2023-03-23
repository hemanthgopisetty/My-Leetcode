class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>&ans,vector<int>&curset,int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(curset);
            return ;
        }
        curset.push_back(nums[idx]);
        backtrack(nums,ans,curset,idx+1);
        curset.pop_back();
        backtrack(nums,ans,curset,idx+1);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curset;
        backtrack(nums,ans,curset,0);
        return ans;
    }
};