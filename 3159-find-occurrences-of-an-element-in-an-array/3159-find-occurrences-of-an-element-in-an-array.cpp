class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
       unordered_map<int,int> x_map;
        
        int count=0;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==x)
           {
               count++;
               x_map[count]=i;// i -> index
           }
       }
    
        for(int i=0;i<queries.size();i++){
            if(x_map.find(queries[i])!=x_map.end())//if in map
            {
                queries[i]=x_map[queries[i]];
            }
            else
            {
                 queries[i]=-1;
            }
        }
        return queries;
    }
};