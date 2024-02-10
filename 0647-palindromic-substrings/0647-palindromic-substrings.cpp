class Solution {
public:
    bool check(string st){
        string pst=st;
        reverse(pst.begin(),pst.end());
        return st == pst;
    }
    int countSubstrings(string s) {
        
        int count=0,n=s.size();
        
        for(int i=0;i<n;i++){
            string x="";
            x += s[i];
            for(int j=i+1;j<n;j++){
                x += s[j];
                if(check(x)){
                    count++;
                }
            }
        }
        count += n;
        return count;
    }
};