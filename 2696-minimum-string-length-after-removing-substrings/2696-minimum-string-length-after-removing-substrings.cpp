class Solution {
public:
    int minLength(string s) {
        //Assume A and C as Open Parantheses
        //B and D as Closed Parantheses
        stack<char>st;
        for(auto c:s)
        {
            if(c=='B' and st.size() and st.top()=='A' )
            {
                st.pop();
            }
            else if(c=='D' and st.size() and st.top()=='C' )
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        return st.size();
    }
};