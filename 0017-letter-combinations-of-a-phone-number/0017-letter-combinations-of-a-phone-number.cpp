
class Solution {
public:
    vector<string> ans;
    string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
     
    void combination(const string& digits,string cur,int idx)
    {
        if(idx==digits.size())//when our index reaches the cobination size push it to the ans
        {
            cout<<cur<<endl;
            ans.push_back(cur);
            return ;
        }
        
        string value = keyPad[digits[idx]-'0'];//value referencing the pad for particular digit
        for(auto i=0;i<value.size();i++)//traverse the pad
        {
            cur.push_back(value[i]);
            combination(digits,cur,idx+1);
            cur.pop_back();
        }
    }
     
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return ans;
        }
        int len = digits.size();
        combination(digits,"",0);
        return ans;
    }
};
/*
we need to write a func that gonna attach the all possibilties of a string b to the string a
from every string we need to iterate and recurse the all posibilties
*/