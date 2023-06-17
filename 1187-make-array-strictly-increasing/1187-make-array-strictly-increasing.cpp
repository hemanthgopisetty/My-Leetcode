class Solution {
public:
    bool ok;
    vector<vector<int>>dp;
    int dfs(vector<int>& arr1, vector<int>& arr2,int i,int j,int prev)
    {
        if(i==arr1.size())
        {
            ok=true;
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=1e9;
        if(arr1[i]>prev)
        {
            int no_replace=dfs(arr1,arr2,i+1,j,arr1[i]);
            ans=min(ans,no_replace);
        }
        j=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        
        int replace=1e9;
        if(j<arr2.size())replace=1+dfs(arr1,arr2,i+1,j+1,arr2[j]);
        ans=min(ans,replace);
        return dp[i][j]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2),end(arr2));
        int n1=arr1.size(),n2=arr2.size();
        dp.resize(n1+1,vector<int>(n2+1,-1));
        ok=false;
        int ans=dfs(arr1,arr2,0,0,-1);
        if(!ok)ans=-1;
        return ans==INT_MAX?-1:ans;
    }
};