class Solution {
public:
    vector<vector<int>>ans;
   void fn(int idx,int n,int k,vector<int>&cur)
    {
        //curset size must be 2
       //for every element i have to try the combination with other elements as well
       //1,2 1,3 1,4
       if(cur.size()==k)
       {
           ans.push_back(cur);
           return ;
       }
       
       for(auto i=idx;i<n+1;i++)
       {
           cur.push_back(i);//1->1,2 1->1,3 1->1,4
            fn(i+1,n,k,cur);//1,2 ->1,3 ->1,4
            cur.pop_back();//1,2 -> 1 1,3 -> 1 1,4 ->1
       }
       
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>cur;
        fn(1,n,k,cur);
        return ans;
    }
};