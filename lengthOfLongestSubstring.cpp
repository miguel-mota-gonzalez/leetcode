/*
 Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int retVal = 0;
        string str("");

        int i = 0;
        while(i<s.size() && retVal <= s.size()-i){
            size_t foundPos=-1;
            int j=i;

            for(; j<s.size(); j++){
                foundPos=str.find(s[j]);
                if(foundPos==std::string::npos){
                    str+=(s[j]);
                }else{
                    if(str.size()>retVal){
                        retVal=str.size();
                    }
                    str.clear();
                    break;
                }
            }

            if(str.size()>retVal){
                retVal=str.size();
            }

            if(j==s.size()){
                str.clear();
                i++;
            }
            else{
              i+=(foundPos+1);
            }
        }

        return retVal;
    }
};


