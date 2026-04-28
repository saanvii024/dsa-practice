class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;
        
        string word;
        string result;
        int maxCount = 0;
        
        for(int i = 0; i <= paragraph.size(); i++) {
            if(i < paragraph.size() && isalpha(paragraph[i])) {
                word += tolower(paragraph[i]);
            } 
            else if(!word.empty()) {
                if(bannedSet.find(word) == bannedSet.end()) {
                    freq[word]++;
                    if(freq[word] > maxCount) {
                        maxCount = freq[word];
                        result = word;
                    }
                }
                word.clear();
            }
        }  
        return result;
    }
};