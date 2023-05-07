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
        for(auto i=0;i<k;i++)
        {
            if(a[s[i]-'a'])
            {
                cnt++;
            }
        }
        ans=max(ans,cnt);
        for(auto i=k;i<n;i++)
        {
            if(i-k>=0 and a[s[i-k]-'a'])
            {
                cnt--;
            }
            if(a[s[i]-'a'])
            {
                cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};