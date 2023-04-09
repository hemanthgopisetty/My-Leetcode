class Solution {
public:
    void dfs(vector<int>& candidates,vector<int>&currset,vector<vector<int>>&ans,int idx,int target)
    {
        if(target<0)
        {
            return ;
        }
        //base case 
        if(target==0)
        {
            ans.push_back(currset);
            return ;
        }
        
        for(auto i=idx;i<candidates.size();i++)
        {
            //should not contain duplicates
            if(i>idx and candidates[i]==candidates[i-1]) continue ;
            
            //why break bcouz we array is sorted 
            if(candidates[i]>target)break;
            
            currset.push_back(candidates[i]);
            
            //from current set,go backtrack
            dfs(candidates,currset,ans,i+1,target-candidates[i]);
            
            currset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>currset;
        
        vector<vector<int>>ans;
        
        sort(candidates.begin(),candidates.end());
        
        dfs(candidates,currset,ans,0,target);
        return ans;
    }
};