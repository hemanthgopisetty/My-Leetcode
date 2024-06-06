class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int grpsz) {
        int n=hand.size();
        if(n%grpsz!=0)return false;
        map<int,int> hm ;
        for(auto it:hand)hm[it]++;
        while(hm.size())
        {
            int curr=hm.begin()->first;
            for(int i=0;i<grpsz;i++)
            {
                if(hm[curr+i]>0)
                {
                    hm[curr+i]--;
                    if(hm[curr+i]==0)
                    {
                        hm.erase(curr+i);
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true ;
    }
};