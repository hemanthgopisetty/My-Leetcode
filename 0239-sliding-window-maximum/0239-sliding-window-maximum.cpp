class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> a;
        int l=0,r=0;
        priority_queue<pair<int,int>> pq;
     while(r<nums.size())
       {
         //push every element to the priority_queue
         pq.push({nums[r],r});
         //if cur_elem not equal to the size of k then increase r 
         if(r-l+1<k) r++;
         //if equal to k
         else if(r-l+1==k)
         {
            //pop the all elements in the queue until cur<l
            while(pq.top().second<l)pq.pop();
            //we will be having the one element every time we push 
            //to the pq
            a.push_back(pq.top().first);
           //increase window size on both the sides
            l++,r++;
         }
       }
      return a;
    }
};