class Solution {
public:
    string compressedString(string word) {
        int r=0;
        string comp="";
        while(r<word.size())
        {
            int cnt=0;
            char curchar=word[r];
            while(r<word.size() and cnt<9 and word[r]==curchar)
            {
                cnt++;
                r++;
            }
            comp+=to_string(cnt)+curchar;
        }
        return comp;
    }
};