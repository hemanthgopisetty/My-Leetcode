class Solution {
public:
    int bs(int target,vector<vector<int>>&items)
    {
        int l=0;
        int h=items.size()-1;
        int maxB=0;
        while(l<=h)
        {
            int m = (l+h)/2;
            if(items[m][0]>target)
            {
                h=m-1;
            }
            else
            {
                maxB=max(maxB,items[m][1]);
                l=m+1;
            }
        }
        return maxB;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        vector<int>ans(n,0);
        //sort the items
        sort(items.begin(),items.end(),[](vector<int>&a,vector<int>&b){
            
            return a[0]<b[0];
            
        });
        //Preprocees
        //Max Beauty Value
        int maxB = items[0][1];
        for(int i=0;i<items.size();i++)
        {
            maxB = max(items[i][1],maxB);
            items[i][1]=maxB;
        }
        //for maximum beauty do binary search
        for(int i=0;i<n;i++)
        {
            int beauty = bs(queries[i],items);
            ans[i]=beauty;
        }
        return ans;
    }
};

/*

Sort the array based on the price
we have to find the maximum beauty price less than the given query price

do binary search while query 
nlogn time complexity , 
if we do bs on sorted array based on the item's price it will return less or equal index items price
then from  o to index we will track maxBeauty Value
this would cause O(queries*M)(M is index valuer every ) , it creates redudant check right ?
to solve this we track maxValue upto each index that would give maxBeauty in O(1) 

buteforce time complexity is we will traverse the nlogn + O(n^2)
or O(n^2)
*/