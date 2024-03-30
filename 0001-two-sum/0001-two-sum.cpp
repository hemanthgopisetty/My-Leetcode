class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> hm;
        for(auto i=0;i<nums.size();i++)
        {
            if(hm.find(target-nums[i])!=hm.end())
            {
                ans.push_back(hm[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else
            {
                hm[nums[i]]=i;
            }
        }
        //used hashmap
        return ans;
    }
};