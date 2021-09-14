/*
Container With Most Water

Solution
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
   Hide Hint #1  
The aim is to maximize the area formed between the vertical lines. The area of any container is calculated using the shorter line as length and the distance between the lines as the width of the rectangle.
Area = length of shorter vertical line * distance between lines
We can definitely get the maximum width container as the outermost lines have the maximum distance between them. However, this container might not be the maximum in size as one of the vertical lines of this container could be really short.


   Hide Hint #2  
Start with the maximum width container and go to a shorter width container if there is a vertical line longer than the current containers shorter line. This way we are compromising on the width but we are looking forward to a longer length container.
*/

class Solution {
public:
    
    int maxArea(vector<int>& height) {

        vector<int> level = height;
        int retVal=INT_MIN;
        
        // sort
        std::sort(level.begin(), level.end());
        
        int start=0;
        int end=height.size()-1;
        int prevLevel=0;
        for(int &l : level){
            
            if(l>0 && l==prevLevel)
                continue;
            
            while(start < end){
                if(height[start]-l<0){
                    start++;
                    continue;
                }
                if(height[end]-l<0){
                    end--;
                    continue;
                }
                break;
            }
            
            if((end-start)*(l) > retVal)
                retVal=(end-start)*(l);
            
            prevLevel=l;
        }
        
        return retVal;
    }
};