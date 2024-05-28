class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
//        unordered_map<int,int> x_map;
        
//         int count=0;
//        for(int i=0;i<nums.size();i++)
//        {
//            if(nums[i]==x)
//            {
//                count++;
//                x_map[count]=i;// i -> index
//            }
//        }
    
//         for(int i=0;i<queries.size();i++){//q.logq
//             if(x_map.find(queries[i])!=x_map.end())//if in map(logn)
//             {
//                 queries[i]=x_map[queries[i]];
//             }
//             else
//             {
//                  queries[i]=-1;
//             }
//         }
//         return queries;
        
        vector<int>ans,xidx;
        for(int i=0;i<nums.size();i++)if(nums[i]==x)xidx.push_back(i);
        for(int i=0;i<queries.size();i++){
            ans.push_back(queries[i]-1<xidx.size()?xidx[queries[i]-1]:-1);
        }
        return ans ;
    }
};