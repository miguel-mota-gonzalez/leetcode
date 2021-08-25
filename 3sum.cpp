/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> retVal;
        int sum=0;
        
        if(nums.size()<3)
            return retVal;
        
        std::sort(nums.begin(), nums.end());   
        
        for(int i=0; i<nums.size()-2; i++){
            
            if(i>0 && nums[i]==nums[i-1])
                continue;
                            
            int j = i+1;
            int k = nums.size()-1;
            
            while (j < k) {                                
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == 0) {                                                        
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[j];
                    tmp[2] = nums[k];
                    retVal.push_back(tmp);
                    j++;
                    k--;                
                    
                } else if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                }
                                
                while( k < nums.size()-1 &&  j < k && nums[k]==nums[k+1])
                    k--;                
                                
                while(j > i+1 && j < k && nums[j]==nums[j-1])
                    j++;                        
            }            
            
        }
        
        return retVal;
    }
};