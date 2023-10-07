class Solution {
public:
    string removeKdigits(string num, int k) {
         string ans="";
        for(char &c:num)
        {
            while(ans.size() && ans.back()>c &&k)
            {
                ans.pop_back();
                k--;
            }
            if(ans.size()||c!='0')ans.push_back(c);
        }
        while(ans.size()&&k--)          // <-------this look is to make sure we fulfil the deletion condition
        {
            ans.pop_back();
        }
        return (ans=="")?"0":ans;
    }
    
    
};

//1432219
//1122349 if we remove any k didgits
//1221
//1219 if we remove according to the sequence

//then we need to maintain motonocity 
//becuase 