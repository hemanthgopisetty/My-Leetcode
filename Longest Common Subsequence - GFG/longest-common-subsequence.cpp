//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
       int n=s2.size();
       int m=s1.size();
       //dp[i,0] =>represents no characer in s2 ,so no common subsequencce
       //dp[0,j] =>represents no characer in s1 ,so no common subsequencce
       
       //dp[i,j] =>represents common characters in s1 and s2 upto i-1,j-1
       
       int dp[m+1][n+1]{};
       for(auto i=0;i<=m;i++)
       {
          for(auto j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                {
                    dp[i][j]=0;
                }
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                // cout<<dp[i][j]<<endl;
            }
       }
       return dp[m][n];//=>Actually refers to the lcs of upto s1[m-1]s2[n-1];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends