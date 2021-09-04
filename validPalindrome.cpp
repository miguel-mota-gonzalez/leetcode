/*
Valid Palindrome

Solution
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        bool retVal=true;

        int start=0,pos=s.size()-1;
        while(start!=pos && start < pos){
            
            if(!isalnum(s[start])){
                start++;
                continue;
            }
            
            if(!isalnum(s[pos])){
                pos--;
                continue;
            }
            
            if(tolower(s[start++])!=tolower(s[pos--])){
                retVal=false;
                break;
            }
        }

        return retVal;
    }
};
