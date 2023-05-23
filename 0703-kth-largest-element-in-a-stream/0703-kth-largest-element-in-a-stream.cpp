class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    //pass by value -> k,pq
    int kthelement(int k,priority_queue<int> pq)
    {
        
        while(k-- > 1 and !pq.empty()) {   
            pq.pop();
        } 
        cout<<pq.top()<<endl;
        return pq.top();
    }
    KthLargest(int k, vector<int>& nums) {
         this->k=k;
        for(auto i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(pq.size() > this->k)
        {
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */