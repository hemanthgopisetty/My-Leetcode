class Solution {
public:
    int minChanges(string s) {
        int ans=0;
        for(int i=0;i<s.size()-1;i+=2)
        {
            if(s[i]!=s[i+1])
            {
                ans++;
            }
        }
        return ans;
    }
};
/*
Given String is binary , 0 indexed ,had even length

Given string is beautiful , if it's possible to partition it into one or more substrings such that
    : each substring has an even length
    : each substring contains only only 1's or o's

You can change any character in s to 0 or 1


Each partiton which is even length should contain only zero's and one's
if any of the partition of even length differs above rules
then it's a change
*/