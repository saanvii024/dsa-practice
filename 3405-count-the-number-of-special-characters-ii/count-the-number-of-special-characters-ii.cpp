/* class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for(int i = 0; i < word.size(); i++) {

            if(islower(word[i])) {

                m1[word[i]] = i;

            } else {

                char lower = tolower(word[i]);

                if(m2.count(lower) == 0) {
                    m2[lower] = i;
                }
            }
        }

        int count = 0;

        for(auto p : m1) {

            char ch = p.first;

            if(m2.count(ch) &&
               m1[ch] < m2[ch]) {

                count++;
            }
        }

        return count;
    }
};*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> m1(26, -1);
        vector<int> m2(26, -1);

        for(int i = 0; i < word.size(); i++) {
            if(islower(word[i])) {
                m1[word[i] - 'a'] = i;
            } else {
                if(m2[word[i] - 'A'] == -1) {
                    m2[word[i] - 'A'] = i;
                }
            }
        }
        int count = 0;
        for(int i = 0; i < 26; i++) {

            if(m1[i] != -1 &&
               m2[i] != -1 &&
               m1[i] < m2[i]) {

                count++;
            }
        }
        return count;
    }
};