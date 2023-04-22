class Solution {
public:
    bool isIsomorphic(string s, string t) {
       map<char,int> hm1;
       map<char,int> hm2;
       
      for(auto i=0;i<s.size();i++)
      {
          if(hm1[s[i]]!=hm2[t[i]])
          {
              return false;
          }
          
          hm1[s[i]]=i+1;
          hm2[t[i]]=i+1;
      }
      return true;
    }
};