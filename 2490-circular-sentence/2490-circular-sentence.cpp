class Solution {
public:
    bool isCircularSentence(string s) {
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' and s[i-1]!=s[i+1])return false;
        }
        return s[0]==s[s.size()-1];
    }
};
/*
    Idea -> 
    if i == " ":
       if(s[i-1]!=s[i+1]):
          return false
    
    return s[0] == s[n-1]
*/