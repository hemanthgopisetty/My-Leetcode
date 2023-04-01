class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        //we can approach this problem by observing the pattern in the given testcases
        //one of the tricky part to appraoch in the problem is 
        //what if a element exists in the both the array's
        //then that will be the answer bcouz if there is no intersection of the two array's
        //then we will take min of two aaray's and we will form a double digit that is actually greater than the intersection the two array's
        
        //to find the intersection in the array's we gonna use binary_search 
        //on the nums2 array and we perfom the bs on nums1 
        //if any of the element matches then we return the nums1
        
        //to perfom the binary search we gonna sort the two given array's
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        for(auto i=0;i<n;i++)// n time
        {
            int start=0;
            int end=m-1;
            //logn time
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums1[i]==nums2[mid])
                {
                    return nums1[i];
                }
                
                if(nums1[i]>nums2[mid])
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }//TC ->n*log(n) TIME;
        
        
        //if the execution comes here then there's no intersection element
        
        //minimum of two array's addtion is the answer
        
        int min1=*min_element(nums1.begin(),nums1.end());
        int min2=*min_element(nums2.begin(),nums2.end());
        
        if(min2>min1)
        {
            return min1*10+min2;
        }
        return min2*10+min1;
    }
};