/*
Add Binary

Solution
Given two binary strings a and b, return their sum as a binary string.

 

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        
        int _size = std::max(a.size(), b.size());
        string retVal;
        
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());
        
        bool rem=false;
        for(int i=0; i<_size; i++){
            
            if(i<a.size() && i<b.size()){
                if(a[i]==b[i]){
                    retVal+=(rem ? '1' : '0');
                    rem = false;
                    
                    if(a[i]=='1')
                        rem=true;
                }
                else{
                    retVal+=(rem ? '0' : '1');
                }                
            }
            else{
                string *aliveStr= (i<a.size() ? &a : &b);
                
                if((*aliveStr)[i]=='0'){
                    retVal+=(rem ? '1' : '0');
                    rem=false;
                }
                else{
                    retVal+=(rem ? '0' : '1');
                }
            }    
        }
        
        if(rem)
            retVal+='1';                
        
        std::reverse(retVal.begin(), retVal.end());
        
        return retVal;
    }
};