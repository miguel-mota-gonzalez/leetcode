/*
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.


THIS IS NOT A O(M + N) solution.. sorry!
*/

class Solution {
public:
    string minWindow(string s, string t) {
        string retVal="";
        map<char,int> targetItems;
        string allowed;
        
        // build the t items reference
        for(auto &c : t){
            if(targetItems.find(c)==targetItems.end()){
                targetItems.insert(pair<char,int>(c,1));
                allowed+=c;
            }
            else{
                targetItems[c]++;
            }
        }

        // In this queue we are keeping the elements that were already found
        // so we can rebuild the status
        queue<int> lastFound;
        int minStart=-1;
        int minEnd=-1;
        int start=-1; 
        int end=0;
        map<char,int> tI = targetItems;
        for(char &c : s){            
            // Is this character requiered?
            if(allowed.find(c)!=string::npos){            
                // If the string found hasn't started not lastfound queue                 
                if(start==-1 && lastFound.size()==0){
                    start=end;
                }                
                
                // save this item
                lastFound.push(end);
                
                // now we check the keys, are we still expecting this item?
                int &tmpVal = tI[c];
                if(tmpVal>0)
                    tmpVal--;
                
                // Do we have all what we need?
                if(tmpVal==0)
                    tI.erase(c);                             
                
                // do we have all the items?
                if(tI.size()==0){                 ;
                    if(minStart==-1){
                        minStart=start;
                        minEnd=end;
                    }
                    else if(end-start < minEnd-minStart){
                        minStart=start;
                        minEnd=end;                        
                    }                    
                    
                    while(true){
                        // Remove the first found
                        lastFound.pop();                    

                        // now start is the next element
                        start = lastFound.front();                           

                        // Reset the map with the elemwents we are looking for
                        tI = targetItems;

                        //Reduce the existing from the new map                                      
                        queue<int> qTmp=lastFound;                    
                        while(!qTmp.empty()){
                            int &tmpVal2 = tI[s[qTmp.front()]];
                            if(tmpVal2>0)
                                tmpVal2--;
                            if(tmpVal2==0){
                                // Remove this item
                                tI.erase(s[qTmp.front()]);                 
                            }  
                            qTmp.pop();
                        }
                        
                        if(tI.size()>0){
                            break;
                        }
                        else{
                            if(end-start < minEnd-minStart){
                                minStart=start;
                                minEnd=end;                        
                            }
                        }
                    }
                }
            }
            
            end++;
        }
        
        if(minStart!=-1){
            retVal = s.substr(minStart, minEnd-minStart+1);
        }
            
        return retVal;
    }
};
