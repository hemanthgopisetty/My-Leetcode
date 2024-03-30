class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        int n = s.size();
        unordered_map<int,int> hm ;
        int l=0;
        for(int i=0;i<n;i++)
        {
            hm[s[i]]++;
            while(hm[s[i]]==3)
            {
                hm[s[l++]]--;
            }
            ans = max(ans,i-l+1);
        }
        //SLiding window 
        return ans ;
    }
};