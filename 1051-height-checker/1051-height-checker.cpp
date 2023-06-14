class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>nums=heights;
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(auto i=0;i<nums.size();i++)
        {
            if(nums[i]!=heights[i])cnt++;
        }
        return cnt;
    }
    
};