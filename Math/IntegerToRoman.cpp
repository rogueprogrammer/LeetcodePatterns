// https://leetcode.com/problems/integer-to-roman/submissions/

/*
Start off with writing out mapping for the ones, tens, hundreds, thousands first. It's pretty easy to come up with solution from there. 
Just build the string from thousands place and reduce the problem to hundreds place, tens place, ones place, etc. and return the final string. easy peasie 
*/

class Solution {
public:
    
    vector<string> ones = {"", "I","II","III","IV","V","VI","VII","VIII","IX"};
    vector<string> tens = {"", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string> hundreds = {"", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string> thousands = {"", "M","MM","MMM"};
    
    string intToRoman(int num) {
        /// 3248
        // 637
        string thou = "";
        if(num >= 1000){
            thou = thousands[num/1000];
            num -= ((num/1000) * 1000);
        }
        string hund = "";
        if(num >= 100){
            hund = hundreds[num/100];
            num -= ((num/100)*100);
        }
        
        string ten = "";
        if(num >= 10){
            ten = tens[num / 10];
            num -= (num/10)*10;
        }
        string one = "";
        if(num >= 1){
            one = ones[num];
        }
        
        return thou + hund + ten + one;
    }
};
