class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(auto it:s)
        {
            if(it=='{' or it=='(' or it=='[')
            {
                stk.push(it);
            }
            else
            {
                if( (!stk.empty()) 
                      and 
                   (stk.top()=='{' and it=='}' or 
                    stk.top()=='(' and it==')' or 
                    stk.top()=='[' and it==']'
                   )
                   
                  )
                {
                    stk.pop();
                }
                else return false;//means not matching closing character 
            }
        }
        
        return stk.empty();
    }
};