class Solution {
public:
    
//     int decode(string& s, int idx, int n)
//     {
//         if(idx < n && s[idx] == '0') return 0;
//         if(idx >= n)
//             return 1;
        
//         if(dp[idx] != -1) return dp[idx];
        
//         int ways = 0;
        
//         // Pick single
//         if(s[idx] != '0') ways = decode(s, idx+1, n);
            
//         // Pick couple
//         if(idx+1 < n && ((s[idx] == '1' && s[idx+1] <= '9') || (s[idx]=='2' && s[idx+1] < '7')))
//            ways += decode(s, idx+2, n);
           
//         return dp[idx] = ways;
//     }
    
    int numDecodings(string s) {
       
        int n = s.size();
        // memset(dp, -1, sizeof(dp));
        //return decode(s, 0, n);
        vector<int> dp(s.size()+1);
        dp[0]=1;
        if(s[0]=='0')dp[1]=0;
        else dp[1]=1;
        for(int i=2;i<=s.size();i++){
            int way1,way2;
            if(s[i-1]=='0')way1=0;
            else way1=dp[i-1];
            if(stoi(s.substr(i-2,2))<=26&&stoi(s.substr(i-2,2))>0&&s[i-2]!='0')way2=dp[i-2];
            else way2=0;
            dp[i]=way1+way2;
        }
        return dp[s.size()];
    }
};