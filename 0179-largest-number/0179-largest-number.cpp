bool comp(string a,string b)
{
    //string are comparable
    cout<<"a "<<a<<endl;
    cout<<"b "<<b<<endl;
    return a+b > b+a ;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        vector<string>s(n);
        for(int i=0;i<n;i++)
        {
            s[i]=to_string(nums[i]);
        }
        sort(begin(s),end(s),comp);
        string result;
        for(int i=0;i<n;i++)
        {
            result+=s[i];
        }
        
        return result[0]=='0'?"0":result;
    }
};