/*
String to Integer (atoi)
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/

class Solution {
public:
    int myAtoi(string str) {
        long retVal=0;
        string cleaned("");
        bool numberStarted=false;
        bool isNegative=false;
        bool isPositive=false;

        for(char c : str){

            if(isdigit(c)){
                numberStarted=true;
                if(c=='0' && cleaned.size()==0){
                    continue;
                }
                cleaned+=c;
            }else{
                if(numberStarted)
                    break;

                if(c=='+' && !isPositive && !isNegative){
                    isPositive=true;
                    continue;
                }
                else if(c=='+'){
                    return 0;
                }

                if(c=='-' && !isNegative && !isPositive){
                    isNegative=true;
                    continue;
                }else if (c=='-'){
                    return 0;
                }

                if(c==' ' && !isNegative && !isPositive){
                    continue;
                }

                return 0;
            }
        }

        string maxInt = (isNegative ? "2147483648" : "2147483647");

        if(cleaned.size()>10){
             cleaned=maxInt;
        } else if(cleaned.size()==10){
            for(int i=0; i<cleaned.size(); i++){
                if(((int)maxInt[i])-((int)cleaned[i]) > 0){
                    break;
                }else if (((int)maxInt[i])-((int)cleaned[i]) < 0){
                    cleaned = maxInt;
                }
            }
        }

        long pot = 1;
        for (std::string::reverse_iterator rit=cleaned.rbegin(); rit!=cleaned.rend(); ++rit){
            retVal += ( (((long)(*rit))-48)*pot );
            pot*=10;
        }

        if(isNegative)
            retVal*=-1;

        return retVal;
    }
};

