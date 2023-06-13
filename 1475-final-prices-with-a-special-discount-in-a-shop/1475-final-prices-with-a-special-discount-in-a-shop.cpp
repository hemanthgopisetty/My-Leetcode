class Solution {
public:
    //Special Offer => Orginal Price - Discount
    //Discount  = prices[i]<=prices[j]
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int,int>>st;
        vector<int>ans=prices;
        for(auto i=0;i<prices.size();i++)
        {
            while(!st.empty() and st.top().first>=prices[i])
            {
                auto it=st.top();
                st.pop();
                ans[it.second]=it.first-prices[i];
            }
            st.push({prices[i],i});
        }
        return ans;
    }
};