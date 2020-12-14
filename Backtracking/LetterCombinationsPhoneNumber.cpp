class Solution {
public:
    vector<string> mappings = 
    {
        "abc", "def", "ghi", "jkl", "mno","pqrs", "tuv", "wxyz"
    };
    
    /*
    a                  b                 c             [index = 0, digit = 2]
  ad  ae  af        bd    be   bf       cd ce cf       [index = 1, digit = 3]
    
    Computing runtime: 
      
   Consider "234". Recursive tree looks like:
          a                   b                     c
       ad   ae   ef         bd    be   bf          cd    ce   cf
    adg adh adi
   thus runtime = O(3^N + 3^M), where N is the number of digits that have 3 possible letters, and M is the number of digits
   that have 4 possible digits
   
    */
    // digits = "23"
    void dfs(vector<string>& res, string& digits, int& index, string& slate){
        if(index == digits.size()){
            res.push_back(slate);
            return;
        }
        int digit = digits[index]-'0';
        string cur = mappings[digit-2];
        for(int i = 0; i < cur.size(); ++i){
            slate += cur[i];
            index++;
            dfs(res, digits, index, slate);
            index--;
            slate.pop_back();
        }
    }
    
    

vector<string> letterCombinations(string digits) {
	vector<string> res;
    if(digits == ""){
        return res;
    }
    int index = 0;
    string slate = "";
    dfs(res, digits, index, slate);
    return res;
}

};
