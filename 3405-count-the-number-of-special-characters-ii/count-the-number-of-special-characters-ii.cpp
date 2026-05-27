class Solution {
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
};