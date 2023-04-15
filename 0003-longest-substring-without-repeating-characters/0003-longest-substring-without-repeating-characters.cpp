class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int l=0,r=0;
        map<char,int>seen;
        while(r<s.size())
        {
            seen[s[r]]++;
            
            //until the current character becomes unique decrease 
            //the frequenices of all values to 1
            while(seen[s[r]]>1)
            {
                seen[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};