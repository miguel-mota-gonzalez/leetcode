/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string retVal;
        vector<queue<int>> levels;
        char tmpBuff[2] = {'\0','\0'};
        
        for(string::reverse_iterator it1 = num1.rbegin(); it1!=num1.rend(); it1++){
            queue<int> level;
            tmpBuff[0]=*it1;
            int curr1 = atoi(tmpBuff);
            
            int rm = 0;
            for(string::reverse_iterator it2 = num2.rbegin(); it2 != num2.rend(); it2++){
                tmpBuff[0]=*it2;
                int curr2 = atoi(tmpBuff);
                int smallMult = (curr1*curr2)+rm;
                rm=0;
                
                while(smallMult>9){
                    rm+=10;
                    smallMult-=10;
                }                
                rm/=10;
                
                level.push(smallMult);
            }
            
            if(rm>0)
                level.push(rm);
            
            levels.push_back(level);
        }
        
        if(levels.size()>0){
            stack<int> result;
            int pos=0;
            int rm = 0;
            
            while(true){
                int currVal = rm;
                int emptyLists=0;
                rm = 0;
                
                for(int i=0; i<levels.size(); i++){
                    
                    if(levels[i].empty()){
                        emptyLists++;
                        continue;
                    }
                    
                    if(i<=pos){
                        currVal+=levels[i].front();
                        levels[i].pop();
                    }
                }
                
                while(currVal>9){
                    rm+=10;
                    currVal-=10;
                }                
                rm/=10;                
                
                if(emptyLists==levels.size()){
                    if(currVal > 0)
                        result.push(currVal);
                    break;
                }
                else{
                    result.push(currVal);
                }
                
                pos++;
            }
         
            bool numberStarts=false;
            while(!result.empty()){
                
                if(!numberStarts && result.top()==0){
                    result.pop();
                    continue;
                }
                
                numberStarts=true;
                retVal+=std::to_string(result.top());
                result.pop();
            }
            std::cout << std::endl;
        }
        
        return (retVal.size()==0 ? "0" : retVal);
    }
};