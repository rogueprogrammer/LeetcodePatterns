/*
https://leetcode.com/problems/longest-palindromic-subsequence/

            b  b   b   a   b
         b  1  
         b     1   
         b         1    
         a             1   
         b                 1
         
         let dp[i][j] = longest palindromic subsequence for the substring s(i, .., j)
         
         consider a string like this: 
         s1    s2     s3    s4    s5   ...   sn 
         and we want to compute dp[s1, s5]
         if s[i] == s[j], then we need to know if s[i+1, .., j-1] is a palindrome, 
                                          which is in dp[i+1][j-1]
         dp[i, j] = dp[i+1, j-1] + 2 if s[i] == s[j]
          
         if s1 != s5, then dp[s1, s5] = max(dp[s1, s4], dp[s2, s5])
                          => dp[i, j] = max(dp[i, j-1], dp[i+1, j])
        
                2      3     3     
         
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        
        for(int len = 0; len < s.size(); ++len){
            
            for(int i = 0; i < s.size(); ++i){
                
                int j = i + len;
                if(j >= s.size()){
                    break;
                }
                if(len == 0){
                    dp[i][j] = 1;
                }
                else if(len == 1){
                    dp[i][j] = (s[i] == s[j]) ? 2 : 1;
                }
                else{
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1] + 2;
                    } else{
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
                
            }
        }
        
        return dp[0][s.size()-1];
    }
};
