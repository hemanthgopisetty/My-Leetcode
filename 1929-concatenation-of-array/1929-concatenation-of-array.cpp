class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans=nums;
        auto it=ans.end();
        ans.insert(it,nums.begin(),nums.end());
        return ans;
    }
};