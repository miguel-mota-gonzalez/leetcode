/*
One Edit Distance

Solution
Given two strings s and t, return true if they are both one edit distance apart, otherwise return false.

A string s is said to be one distance apart from a string t if you can:

Insert exactly one character into s to get t.
Delete exactly one character from s to get t.
Replace exactly one character of s with a different character to get t.
 

Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "", t = ""
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "a", t = ""
Output: true
Example 4:

Input: s = "", t = "A"
Output: true
 

Constraints:

0 <= s.length <= 104
0 <= t.length <= 104
s and t consist of lower-case letters, upper-case letters and/or digits.
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int totalDiff=0;
        
        if(!s.compare(t))
            return false;
        
        if(s.size()==0)
            return t.size();
        
        if(t.size()==0)
            return s.size();
        
        if(s.size()==1 && t.size()==1)
            return true;
        
        int sPos=0;
        int tPos=0;
        while(sPos<s.size() || tPos<t.size()){
            
            if(s[sPos]==t[tPos]){
                sPos++;
                tPos++;
                continue;
            }
            
            if( tPos+1<t.size() && 
                 s.substr(sPos, (s.size()-sPos+1)).compare(t.substr(tPos+1,t.size()-tPos+1))==0 
               ){
                totalDiff++;
                break;
            }
            
            if( sPos+1<s.size() && 
                 t.substr(tPos, (t.size()-tPos+1)).compare(s.substr(sPos+1,s.size()-sPos+1))==0
               ){
                totalDiff++;
                break;
            }
            
            if(tPos==t.size() && sPos<s.size()){
                totalDiff+=s.size()-sPos;
                break;
            }
            
            if(sPos==s.size() && tPos<t.size()){
                totalDiff+=t.size()-tPos;
                break;
            }
            
            if(++totalDiff>1)
                break;
            
            if(sPos<s.size())
                sPos++;
            
            if(tPos<t.size())
                tPos++;
        }
        
        return (totalDiff==1 ? true : false);
    }
};
