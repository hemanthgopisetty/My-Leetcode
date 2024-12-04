class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isp(n+1,true);
        isp[0]=false;
        isp[1]=false;
        for(int i=2;i*i<=n;i++)
        {
            if(isp[i])
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    isp[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(isp[i])count++;
        }
        return count;
    }
};