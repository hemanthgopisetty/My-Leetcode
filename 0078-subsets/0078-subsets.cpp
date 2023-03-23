class Solution {
public:
    void backtrack(vector<int>& nums,vector<vector<int>>&ans,vector<int>&curset,int idx)
    {
        //start making a new state let us assume it as A
        if(idx==nums.size())
        {
            //here only leaf nodes are pushed into the answer 
            ans.push_back(curset);
            return ;
        }
        //pick these element
        curset.push_back(nums[idx]);
        //make a recursive call by this picking state A (try increasing idx upto nums.size())
        backtrack(nums,ans,curset,idx+1);
        //come back from the recusrive call state B (idx hits base case(nums.size))
        //after hitting the base case ,come to the state A
        //remove the last inserted element
        //from state A and make state A as new state A1
        curset.pop_back();
        //make a recursive call by this state A1
        backtrack(nums,ans,curset,idx+1);
        //Close brace ends the state A and it's Childrens
    }
    void backtrack2(vector<int>& nums,vector<vector<int>>&ans,vector<int>&curset,int idx)
    {
        
        //MAKE RECURSIVE CALLS IN ORDER
        //BY ITERATING THE NUMS
        //EVERY RECRUSIVE CALLS TRAVELS FROM IDX TO N-1
        //AFTER HITTING THE LAST ELMENT COME BACK TO THE STATE IDX AND IBCE=REASE IDX+1
        //so every recursive call is a state enter that into the ans
        ans.push_back(curset);
        for(auto i=idx;i<nums.size();i++)
        {
            //pick elements in order
            //pick this element
            curset.push_back(nums[i]);
            //try new combination with next element to current element 
            backtrack2(nums,ans,curset,i+1);
            //remove the current element 
            curset.pop_back();
            //go to a new state
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curset;
        //backtrack1(nums,ans,curset,0);
        backtrack2(nums,ans,curset,0);
        return ans;
    }
};