class Solution {
public:

    struct TrieNode {

        int children[26];
        int bestLength;
        int bestIndex;

        TrieNode() {

            for(int i = 0; i < 26; i++) {
                children[i] = -1;
            }

            bestLength = INT_MAX;
            bestIndex = INT_MAX;
        }
    };

    vector<TrieNode> trie;

    void insert(string& word, int index) {

        int curr = 0;
        int len = word.size();

        // update root
        if(len < trie[curr].bestLength ||
           (len == trie[curr].bestLength && index < trie[curr].bestIndex)) {

            trie[curr].bestLength = len;
            trie[curr].bestIndex = index;
        }

        for(int i = len - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            // create node if absent
            if(trie[curr].children[ch] == -1) {

                trie[curr].children[ch] = trie.size();

                trie.push_back(TrieNode());
            }

            curr = trie[curr].children[ch];

            // update best answer
            if(len < trie[curr].bestLength ||
               (len == trie[curr].bestLength && index < trie[curr].bestIndex)) {

                trie[curr].bestLength = len;
                trie[curr].bestIndex = index;
            }
        }
    }

    int search(string& word) {

        int curr = 0;

        for(int i = word.size() - 1; i >= 0; i--) {

            int ch = word[i] - 'a';

            if(trie[curr].children[ch] == -1) {
                break;
            }

            curr = trie[curr].children[ch];
        }

        return trie[curr].bestIndex;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        trie.push_back(TrieNode());

        for(int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for(int i = 0; i < wordsQuery.size(); i++) {
            ans.push_back(search(wordsQuery[i]));
        }

        return ans;
    }
};