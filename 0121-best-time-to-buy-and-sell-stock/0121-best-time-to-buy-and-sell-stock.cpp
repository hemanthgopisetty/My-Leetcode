class Solution {
public:
/*
To get the maximum profit we need to buy low and sell high                                              
*/
    int maxProfit(vector<int>& prices) {
        int maxprofit {0},minm{prices[0]};
        for(auto i=1;i<prices.size();i++)
        {
            //Use Stored minimum to calculate the profit
            maxprofit=max(maxprofit,prices[i]-minm);
            //Update the minm if the current is minimum
            minm=min(minm,prices[i]);
        }
        return maxprofit;
    }
};