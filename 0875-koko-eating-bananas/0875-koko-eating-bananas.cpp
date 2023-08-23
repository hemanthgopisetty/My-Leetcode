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