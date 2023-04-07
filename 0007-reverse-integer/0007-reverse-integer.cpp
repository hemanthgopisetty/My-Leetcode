class Solution {
public:
    int reverse(int x) {
        
        long ans=0,r=0;
        while(x)
        {
            ans=ans*10+x%10;// find remainder and add its to ans
            
            x/=10;//update the value of x
        }
        //check 32 bit range if ans is in the range of 32 then return
        //else return 0;
        if(ans>INT_MAX || ans<INT_MIN) return 0;
        
        return int(ans);
    }
};