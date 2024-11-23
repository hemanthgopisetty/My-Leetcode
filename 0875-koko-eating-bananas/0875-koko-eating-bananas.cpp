class Solution {
public:
    bool can_koku_eat(vector<int>& piles,int speed,int h)
    {
        long long total_hours =0;
        for(auto it:piles)
        {
            //why ceil means 
            //koku eats all of them instead and will not eat any more bananas during this hour.
            total_hours+=ceil(it/(double)speed);
        }
        return total_hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l=1,r=*(max_element(begin(piles),end(piles)));
        //l and r creates an sorted imaginary array ;
        int ans =-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            
            if(can_koku_eat(piles,mid,h))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        
        return ans ;
    }
    /*
        bs on Imaginary array
        check wether koku can eat all the banans in less than or equal to the given time
        
        
    */
};
/*
piles = [3,6,7,11], h = 8
There are total 8 hours,
Koko needs 5 hours out of 8 hrs
if k==1 ,to get complete the first pile koko needs 3 hrs,second pile koko need 6 hrs ,6+3=9 hrs
if k==2 ,still it crosses 8 hrs
if k==3 ,[1,2,3,4]=>1+2+3+4=10 hrs crosses 8 hrs
if k==4 ,[1,2,2,3]=>1+2+2+3=8hrs  => equals 8 hrs
if k==5 ,[1,2,2,3]=>1+2+2+3=8hrs  => equals 8 hrs
if k==6 ,[1,1,2,2]=>1+1+2+2=6hrs  => less than 8hrs
if k==7 ,[1,1,1,2]=>1+1+1+2=5hrs  => less than 8hrs
if k==8 ,same
if k==9 ,same
if k==10,same
if k==11,[1,1,1,1]=>1+1+1+1=4hrs  => same
.
.
.
.
.
.
.
.
more than max of the array ans is same 

1 to 11 => Check Each time

*/