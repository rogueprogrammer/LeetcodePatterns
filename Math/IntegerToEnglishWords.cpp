/*
Start off with writing logic for under 1000. Keeping in mind complicated numbers like 
16 million One hundred twenty three thousand four hundred seventy nine.
You will have to handle this recursively as you notice that One hundred twenty three is already handled if you handled < 1000 case. So pass in 123 as well as the rest of the number recursively. 
The only vectors of strings needed are 1-20, and then 30, 40, ..., 90. All other numbers are based on these "foundational" numbers.

*/

class Solution {
public:
    
    vector<string> under10 = {  "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

    vector<string> under20 = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    vector<string> under100 = { "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

        
    //2,147,483,647 -> two billion one hundred forty seven million four hundred eighty three thousand six hundred forty seven
    string _numberToWords(int num) {

        if (num == 0) {
            return "";
        }

        if (num >= 1000000000) {
            int dig = num / 1000000000;
            return _numberToWords(dig) + " Billion" + _numberToWords(num - (dig * 1000000000));
        }

        if (num >= 1000000) {
            int dig = num / 1000000;
            return _numberToWords(dig) + " Million" + _numberToWords(num - (dig * 1000000));
        }

        if (num >= 1000) {
            int dig = num / 1000;
            return _numberToWords(dig) + " Thousand" + _numberToWords(num - (dig*1000));
        }

        if (num >= 100) {
            string dig = under10[(num / 100) - 1];
            return " " + dig + " Hundred" + _numberToWords(num - ((num / 100) * 100));
        }

        if (num >= 20) {
            string dig = under100[(num / 10) - 1];
            return " " + dig +  _numberToWords(num - ((num / 10) * 10));
        }

        if (num >= 10) {
            return " " + under20[num % 10];
        }
        
        return " " + under10[num-1];
    }
    
    // trim white spaces left of the first non-space character
    static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    }
    
    //trim white spaces right of the first non-space character
    static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    }
    
   string numberToWords(int num) {
        
       if(num == 0){
            return "Zero";
       }
       
       string res = _numberToWords(num);
       ltrim(res);
       rtrim(res);
       return res;
   }
   
};


