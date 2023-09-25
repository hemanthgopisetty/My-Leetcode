class Solution {
public:
    char findTheDifference(string s, string t) {
/*TIME COMPLEXITY O(N) SPACE COMPLEXITY O(N)*/
//         map<char,int> hm1,hm2;
//         char ans;
//         for(auto i=0;i<s.size();i++)hm1[s[i]]++;
//         for(auto i=0;i<t.size();i++)hm2[t[i]]++;
        
//         for(auto it:hm2)
//         {
//             char dup = it.first;
//             cout<<dup<<" "<<hm2[dup]<<" "<<hm1[dup]<<endl;
//             if(hm2[dup]!=hm1[dup])
//             {  
//                 ans=dup;
//                 break;
//             }
//         }
//         return ans;
        
/*TIME COMPLEXITY O(N) SPACE COMPLEXITY O(N)*/
        char c=0;
        for(auto it:s)c^=it;
        for(auto it:t)c^=it;
        return c;
    }
};