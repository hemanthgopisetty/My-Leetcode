class Solution {
public:
    void generate(vector<string>&ans,string s,int open_char,int close_char,int limit)
    {
        if(s.size()==2*limit)
        {
            ans.push_back(s);
        }
        
        if(open_char<limit)
        {
            generate(ans,s+'(',open_char+1,close_char,limit);
        }
        if(close_char<open_char)
        {
            generate(ans,s+')',open_char,close_char+1,limit);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,"",0,0,n);
        return ans;
    }
};