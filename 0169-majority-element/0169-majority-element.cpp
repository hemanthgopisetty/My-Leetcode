class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Boyes More Voting Algorithm
        //Based on the fact that more than n/2 element is Majority element
        //if the elmenet is same than increment 
        //else decrement 
        //Take majority element as first element
        int majority=nums[0];
        int count=0;
        for(auto i=0;i<nums.size();i++)
    {
            if(count==0){
                count=1;
                majority=nums[i];
            }
            else
            {
                if(majority==nums[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
    }
    return majority;
    }
};