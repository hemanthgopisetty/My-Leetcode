//Forgot Loops pls.....
//Visited Qns
class Solution {
public:
    void dfs(vector<vector<int>>&a,vector<bool>&v,int i)
    {
      //visited i'th node
      v[i]=true;
        
      //"traversing" vertices wise whole list (means whole "graph" )
        
       for(auto j=0;j<a.size();j++)
       {
           if(a[i][j]==1 and !v[j])
           {
               dfs(a,v,j);
           }
       }
    }
    int findCircleNum(vector<vector<int>>&a) {
       //Given adjacent list , find the no of connected and disconnected components 
       int n=a.size();
       
       if(n==0)return 0;
        
       int ans=0;
        
       vector<bool>v(n,false);//vertices visited or not
        
       for(auto i=0;i<n;i++)
       {
            if(!v[i])
            {           //if execution comes here -> then go and visit
                ans++;
                dfs(a,v,i);
            }
       }
        return ans;
    }
};