class Solution {
public:
    /*
    Container with most water -> reduce this problem to larget area of rectangle with 
    given heights
    
    Bute force 
    run two loops and calcualte the max area in each pass ~O(n^2)
    and that area is lenght * widht =>(j-i)*min(a[j],a[i])
    y min() -> ? 
        ans if two vertical poles are same heigh then there is no issue
        but if on of the height is larger and one of the height is smaller than
        the water will store in the container upto the min heigh pole couz the water 
        will pop out of the container 
    
    Optimal solution is : 
    maintain the two pointer 
    move the pointer which has the lower height but why ?
     why we move pointer with the lower height is because 
     we already have the max area with that height - 
     since it is the lower pointer that means 
     that every other distance that is closer will always be a smaller distance 
     with the same or less height which means smaller area. 
    Therefore we do not need to look at every other combination with that pointer.
    */
    int maxArea(vector<int>& height) {
        //intiliaze the r at the last to get the max width
        int area=0;
        int r=height.size()-1;
        int l=0;
        while(l<=r)
        {
            //if any of the pole having less height then water will go out of the container
            area=max(area,(r-l)*min(height[r],height[l]));
            
            //updation of pointer 
            //we already have the max area with that lower height
            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};