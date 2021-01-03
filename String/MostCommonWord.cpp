class Solution {
public:
    // put banned words in a set for quick lookup
    // put paragraph words in another map, as long as they are not in banned
    // if punctuation is encountered, then replace it with a space character
    // return the word that is highest
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        set<string> s_banned(banned.begin(), banned.end());
        pair<string, int> res = {"", 0};
        string word;
        map<string, int> hm;
        for (auto & c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
        
        istringstream iss(paragraph); //USE ISTRINGSTREAM TO PARSE OUT SPACES
        
        while(iss >> word){ // READ EACH STRING FROM ISTRINGSTREAM OBJECT INTO A STRING OBJECT
            auto it = s_banned.find(word);
            if(it == s_banned.end()){
                hm[word]++;
                if(hm[word] > res.second){
                    res = {word, hm[word]};
                }
            }
        }
                
        return res.first;
    }
        
};
