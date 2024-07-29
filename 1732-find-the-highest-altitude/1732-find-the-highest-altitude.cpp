class Solution {
public:
    int largestAltitude(vector<int>& gain) {
         int n = gain.size();
         vector<int>altitude(n+1,0);
         int ans = altitude[0];
         for(int i=1;i<n+1;i++)
         {
             altitude[i]=altitude[i-1]+gain[i-1];
             cout<<altitude[i]<<endl;
             ans = max(ans,altitude[i]);
         }
         
        return ans ;
    }
};
//  altitude[0]=0
//  altitude[1]=altitude[i-1]+gain[i-1] = 0+-5 = -5
//  altitude[2]=altitude[i-1]+gain[i-1] = -5+1 = -4
//  altitude[3]=altitude[i-1]+gain[i-1] = -4+5 = 1
//  altitude[4]=altitude[i-1]+gain[i-1] = 1+0 = 1
//  altitude[5]=altitude[i-1]+gain[i-1] = 1-7 = -6