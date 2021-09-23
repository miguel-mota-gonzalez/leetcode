/*
Longest Substring with At Most Two Distinct Characters

Solution
Given a string s, return the length of the longest substring that contains at most two distinct characters.

 

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
 

Constraints:

1 <= s.length <= 105
s consists of English letters.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int retVal=0;        
        int pos1=0;
        int pos1tmp=0;
        int pos2=0;
        int totalChars=0;
        string different;
                        
        while(pos2<s.size()){
            
            if(different.find(s[pos2])==string::npos){
                totalChars++;
                
                if(totalChars==2)
                    pos1tmp=pos2;
                
                different+=s[pos2];
            }

            if(totalChars<3){
                pos2++;
            }
            else{

                if(pos2-pos1>retVal)
                    retVal=pos2-pos1;
                
                different="";
                pos2=pos1tmp;
                pos1=pos1tmp;
                totalChars=0;
            }
        }
        
        if(pos2-pos1>retVal)
            retVal=pos2-pos1;   
        
        return retVal;
    }
};