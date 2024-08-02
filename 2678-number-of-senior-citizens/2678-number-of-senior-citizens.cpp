class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int ageOne = details[i][11]-'0';
            int ageTwo = details[i][12]-'0';
            int age = ageOne*10 + ageTwo ;
            cnt+=(age>60?1:0);
        }
        return cnt;
    }
};