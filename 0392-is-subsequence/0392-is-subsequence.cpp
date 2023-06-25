class Solution {
public:
    bool dfs(string&s,string&t,int i,int j)
    {
        if(i>=s.size() and j>=t.size())
        {
            return true ;
        }
        if(j>=t.size() and i<=s.size())
        {
            return false;
        }
        
        if(s[i]==t[j])
        {
           return dfs(s,t,i+1,j+1);
        }
        return dfs(s,t,i,j+1);
    }
    bool isSubsequence(string s, string t) {
        return dfs(s,t,0,0);
    }
};