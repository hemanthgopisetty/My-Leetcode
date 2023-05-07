class Solution {
public:
    int maxVowels(string s, int k) {
        vector<bool>a(26,false);
        a['a'-'a']=true ;
        a['e'-'a']=true;
        a['i'-'a']=true;
        a['o'-'a']=true;
        a['u'-'a']=true;
        
        int ans=INT_MIN,cnt=0;
        int n=s.size();
        for(auto i=0;i<n;i++)
        {
            cnt+=(int)a[s[i]-'a'];
            if(i>=k)
            {
                cnt-=(int)a[s[i-k]-'a'];
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};