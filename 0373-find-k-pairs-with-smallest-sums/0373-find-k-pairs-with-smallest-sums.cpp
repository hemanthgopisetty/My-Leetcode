class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;//max_heap
        for(auto it:nums1)
        {
            for(auto it1:nums2)
            {
                int sum=it+it1;
                if(pq.size()<k)
                {
                    pq.push({sum,{it,it1}});
                }
                else if(sum<pq.top().first)
                {
                    pq.pop();
                    pq.push({sum,{it,it1}});
                }
                else break;
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};