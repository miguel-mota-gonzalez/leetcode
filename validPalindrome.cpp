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
        vector<char> tmp;
        
        for(const char &c : s)
            if(isalnum(c))
                tmp.push_back((char)tolower(c));

        int start=0,pos=tmp.size()-1;
        while(start!=pos && start < pos){
            if(tmp[start++]!=tmp[pos--]){
                retVal=false;
                break;
            }
        }

        return retVal;
    }
};