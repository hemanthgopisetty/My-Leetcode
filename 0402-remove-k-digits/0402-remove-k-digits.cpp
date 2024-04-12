class Solution {
public:
    string removeKdigits(string num, int k) {
        //Monotonic Stack
        //String as Stack
        
        string ans="";
        int n = num.size();
        for(int i=0;i<n;i++)
        {
            //current element check
            while(ans.size()>0  and k>0 and ans.back()>num[i])
            {
                ans.pop_back();
                k--;
            }
            //push check
            if(ans.size()>0 || num[i]!='0')ans.push_back(num[i]);
        }
        
        //if still k not equal to zero
        while(k>0 and ans.size()>0)
        {
            ans.pop_back();
            k--;
        }
        
        return (ans==""?"0":ans) ;
    }
};