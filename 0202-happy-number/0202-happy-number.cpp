class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>us;
        while(n!=1)
        {
            if(us.find(n)==us.end())
            {
                us.insert(n);
            }
            else return false;
            
            int x=0,y=0;
            while(n>0)
            {
                x=n%10;
                x*=x;
                y+=x;
                n=n/10;
            }
            n=y;
        }
        return true ;
    }
};