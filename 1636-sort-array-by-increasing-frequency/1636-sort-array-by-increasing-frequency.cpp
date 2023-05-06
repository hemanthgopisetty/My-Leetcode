#define pii pair<int,int>
class compare{
    public : 
  bool operator()(pii ct,pii np)
  {
      if(ct.second==np.second)
      {
          return ct.first<np.first;
      }
      
      return ct.second>np.second;
  }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int>res;
       unordered_map<int,int>hm;
        for(auto it:nums)hm[it]++;
        priority_queue<pii,vector<pii>,compare> pq;
        for(auto it:hm)
        {
            pq.push({it.first,it.second});
        }
        while(!pq.empty())
        {
            while(hm[pq.top().first]>0)
            {
                res.push_back(pq.top().first);
                hm[pq.top().first]--;
            }
            pq.pop();
        }
        return res ;
    }
};