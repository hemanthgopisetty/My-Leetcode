// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int bs(int l,int h)
    {
        if(l==h)return l;
        else
        {
            int m = l+(h-l)/2;
            
            if(isBadVersion(m))
            {
               return  bs(l,m);
            }
            else
            {
               return  bs(m+1,h);
            }
        }
    }
    int firstBadVersion(int n) {
        return bs(1,n);
    }
};