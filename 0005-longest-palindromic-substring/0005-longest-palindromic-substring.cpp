class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[n][n];
        string ans;
        //initially all were false
        memset(dp,false,sizeof(dp));
        //all single characters are palindromes
        ans+=s[0];
        for(auto i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        for(auto start=n-1;start>=0;start--)
        {
            for(auto end=start+1;end<n;end++)
            {
                //if start and end characters are equal
                if(s[start]==s[end])
                {
                    //then do check if it is a single character or 
                    //if it start+1 and end-1 is same 
                    //then it's also a palindrome
                    if(end-start==1 or dp[start+1][end-1])
                    {
                        //then 
                        //from s[start] to s[end] is a palindrome
                        dp[start][end]=true;
                        
                        if(ans.size()<(end-start+1))
                        {
                            ans=s.substr(start,end-start+1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};