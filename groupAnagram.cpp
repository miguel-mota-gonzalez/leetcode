/*
Group Anagrams

Solution
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> retVal;
        map<string,vector<string>> classified;
        
        for(vector<string>::iterator it = strs.begin();
            it != strs.end();
            it++){            
            
            string sorted = *it;
            std::sort(sorted.begin(), sorted.end());
            
            if(classified.find(sorted)==classified.end()){
                vector<string> newVec;
                newVec.push_back(*it);
                classified.insert( pair<string,vector<string>>(sorted, newVec) );
            }
            else{
                classified[sorted].push_back(*it);
            }            
        }
        
        for(map<string,vector<string>>::iterator it = classified.begin();
           it != classified.end();
           it++){
            retVal.push_back(it->second);
        }
     
        return retVal;
    }
};