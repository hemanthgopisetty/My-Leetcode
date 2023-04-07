class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        //Palindrome is a string which reads same forward and bacckward
        //So , string of start == end -> palindrome
        //string of start+1 == end-1  -> palindrome
        //string of start+2 == end-2  -> palindrome
        //....
        //    ....
        //        .... so on
        //So , if a string starting from start and end are palindrome ad it's longest
        //then we can say it's our answer
        //As string length is n ,we may get n*(n-1)/2 strings to check 
        //Those strings are repetetive of some part
        //So , to avoid recomputation we will store the Answers of overlapping problems
        //In an dp array ,which tells us this is palindrome or not
        bool dp[n][n];
        string ans="";
        ans+=s[0];
        memset(dp,false,sizeof(dp));
        //start==end is a palindrome so ,
        for(auto i=0;i<n;i++)dp[i][i]=true;
        //string of start+(1 to n) to end(n to 1) ,need to computed 
        for(auto start=n-1;start>=0;start--){
            for(auto end=start+1;end<n;end++){
                if(s[start]==s[end]){
                    //if it's a two character like ee or aa
                    //or
                    //if this subtring is already palindrome
                    //compute that answer
                    //start+1 and end-1 => we are coming in reverse order
                    if(end-start==1 or dp[start+1][end-1]){
                        //Normal order as palindrome reads same from backward and forward
                        dp[start][end]=true;
                        //Check whether it's longest or not
                        if(ans.size()<end-start+1){
                            ans=s.substr(start,end-start+1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};