class Solution {
public:
    int minimumLength(string s) {
        unordered_map<int,int> hm;
        int len = s.size();
        int cnt = 0 ;
        for(int i=0;i<len;i++)
        {
            hm[s[i]]++;
            if(hm[s[i]]>2)
            {
                hm[s[i]]-=2;
                cnt+=2;
            }
        }
        return len-cnt;
    }
};