class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int>minPrev(n,-1),minNext(n,n),maxPrev(n,-1),maxNext(n,n);
        stack<int>s;
        for(auto i=0;i<n;i++)
        {
            while(!s.empty() and nums[s.top()]>=nums[i])s.pop();
            if(!s.empty())minPrev[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(auto i=n-1;i>=0;i--)
        {
            while(!s.empty() and nums[s.top()]>nums[i])s.pop();
            if(!s.empty())minNext[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(auto i=0;i<n;i++)
        {
            while(!s.empty() and nums[s.top()]<=nums[i])s.pop();
            if(!s.empty())maxPrev[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
        for(auto i=n-1;i>=0;i--)
        {
            while(!s.empty() and nums[s.top()]<nums[i])s.pop();
            if(!s.empty())maxNext[i]=s.top();
            s.push(i);
        }
        long long sum=0;
        for(auto i=0;i<n;i++)
        {
            long long leftMin=i-minPrev[i],rightMin=minNext[i]-i;
            long long leftMax=i-maxPrev[i],rightMax=maxNext[i]-i;
            sum+=((leftMax*rightMax)-(leftMin*rightMin))*nums[i];
        }
        return sum ;
    }
};