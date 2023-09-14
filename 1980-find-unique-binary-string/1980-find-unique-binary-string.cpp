class Solution {
public:
    //generating the all strins of given size 
    //checking every string wether there in the set
    //if not then return that string  
    void dfs(int n,int idx,string s,set<string>&st,vector<string>&p)
     {
        if(idx==n)
        {
            if(st.find(s)==st.end()){
                // cout<<s<<endl;
                p.push_back(s);
            }
            return ;
        }
        
        dfs(n,idx+1,s+"0",st,p);
        if(p.size()!=0)return ;
        
        dfs(n,idx+1,s+"1",st,p);
        
        if(p.size()!=0)return ;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string>st;
        for(auto it:nums)st.insert(it);
        
        int n=nums[0].size();
        vector<string>p;
        string s="";
        dfs(n,0,s,st,p);
        return p[0];
    }
};