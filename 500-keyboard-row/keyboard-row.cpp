class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        //first we create an array of size 26 to store which keyboard row each letter belongs to eg. row[0] -> 'a'
        vector<int> row(26,0); //initializing them all with 0

        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";

        for(char ch : r1){
            row[ch - 'a'] = 1; //marking letters of row1
        }

        for(char ch : r2){
            row[ch - 'a'] = 2;
        }

        for(char ch : r3){
            row[ch - 'a'] = 3;
        }

        vector<string> result;

        for(string word : words){
            int firstrow = row[tolower(word[0])-'a'];
            bool isvalid = true; //assume word is valid now

            for(char ch : word){
                if(row[tolower(ch) - 'a'] != firstrow){
                    isvalid = false;
                    break;
                }
            }

            if(isvalid){
                result.push_back(word);
            }
        }
        return result;
    }
};