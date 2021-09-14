/*
Next Permutation

Solution
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

class Solution {
public:
    
    void nextPermutation(vector<int>& nums) {
        int lastItem = INT_MIN;
        int nextMin = INT_MAX;
        int nextMinIdx = -1;
        bool found = false;
        
        for(int i=nums.size()-1; i>=0; i--){
            
            if(lastItem < nums[i]){
                lastItem = nums[i];
                continue;
            }
            else{
            
                for(int j=nums.size()-1;j>i;j--){
                    if(nums[j]<nextMin && nums[j]>nums[i]){
                        nextMin=nums[j];
                        nextMinIdx=j;
                    }
                }
                    
                if(nextMinIdx!=-1){
                    found = true;
                    int tmp=nums[i];
                    nums[i]=nums[nextMinIdx];
                    nums[nextMinIdx]=tmp;
                    if(i<nums.size())
                        std:sort(nums.begin()+i+1, nums.end());
                    break;
                }
                
            }
        }
        
        if(!found){
            std::sort(nums.begin(), nums.end());
        }
        
    }
};
