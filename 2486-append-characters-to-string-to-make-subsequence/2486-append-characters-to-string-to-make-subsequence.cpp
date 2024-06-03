class Solution {
public:
    int appendCharacters(string s, string t) {
        int tl=0,sl=0;
        
        int sn=s.size(),tn=t.size();
        while(sl<sn and tl<tn)
        {
            if(s[sl]==t[tl])
            {
                tl++;
            }
            sl++;
        }
        return tn-tl;
    }
};