class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>bc,dc;
        vector<int>ans;
        //if ball is there update it 
        
        for(auto q : queries){
            if(bc.find(q[0])!=bc.end()){
                dc[bc[q[0]]]--;
                if(dc[bc[q[0]]]==0) dc.erase(bc[q[0]]);
            }
            bc[q[0]]=q[1]; dc[q[1]]++;
            ans.push_back(dc.size());
        }
        
        return ans;
    }
};