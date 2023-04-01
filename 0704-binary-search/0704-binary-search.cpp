class Solution {
public:
    int bs(vector<int>& a, int target,int l,int r)
    {
        int mid=(l+r)/2;
           if(l<=r)
           {
               if(a[mid]==target)return mid;
               if(a[mid]<target)return bs(a,target,mid+1,r);
               else return bs(a,target,l,mid-1);
           }
        return -1;
    }
    int search(vector<int>& a, int target) {
           
           return bs(a,target,0,a.size()-1);
    }
};