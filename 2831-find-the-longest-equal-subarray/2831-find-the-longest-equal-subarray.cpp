class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>>hm;
        for(int i=0;i<n;i++)
        {
            hm[nums[i]].push_back(i);
        }
        
        int ans=1;
        for(auto&[ele,v]:hm)
        {
            int r=1,l=0,d=0;
            while(r<v.size())
            {
                d+=v[r]-v[r-1]-1;
                while(d>k)
                {
                    d-=(v[l+1]-v[l]-1);
                    l++;
                }
                ans=max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};