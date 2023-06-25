class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        int r=nums.size()-1,l=0;
        int n=nums.size();
        while(l<r)
        {
            string s=to_string(nums[l]);
            string s1=to_string(nums[r]);
            s+=s1;
            cout<<s<<endl;
            int x=stoi(s);
            cout<<x<<endl;
            ans+=x;
            l++,r--;
        }
        if(n%2==1)ans+=nums[l];
        return ans;
    }
};