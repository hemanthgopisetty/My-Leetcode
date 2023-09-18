#define pii pair<int,int>
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
         //find the soliders
        int rows = mat.size();
        int cols = mat[0].size();
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<rows;i++)
        {
            int count_soliders=0;
            for(int j=0;j<cols;j++)
            {
                if(mat[i][j]==1)
                {
                    count_soliders++;
                }
            }
             //push them into the priority_queue with pair 
             pq.push(make_pair(count_soliders,i));
        }
        
        //pop the k int vector
        vector<int> ans;
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

//How binary search is applied here ?
