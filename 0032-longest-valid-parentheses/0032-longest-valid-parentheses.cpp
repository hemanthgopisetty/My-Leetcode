class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans=0;
        st.push(-1);//to have a potential valid parantheses
        for(auto i=0;i<s.size();i++)
        {
            if(s[i]=='(')//open ->push
            {
                st.push(i);
            }
            else//closed ->pop
            {
               st.pop();
               if(st.empty())st.push(i);//extra bracket , from here potential valid parantheses start's
               else ans=max(ans,i-st.top());
            }
        }
        return ans;
    }
};