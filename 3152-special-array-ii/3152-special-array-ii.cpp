class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>ps(n,0);
        for(int i=1;i<n;i++)
        {
            ps[i]=ps[i-1];
            if(nums[i-1]%2 == nums[i]%2)
            {
                ps[i]++;
            }
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++)
        {
            int from=queries[i][0];
            int to=queries[i][1];
            ans.push_back(ps[from]==ps[to]);
        }
        return ans;
    }
};