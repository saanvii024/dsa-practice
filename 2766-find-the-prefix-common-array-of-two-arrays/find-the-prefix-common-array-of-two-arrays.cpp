class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans;
        vector<int> temp;
        int count = 0; 
        for(int i=0; i < n; i++){
            for(int j = 0; j < temp.size(); j++){
                if(A[i]==temp[j] || B[i]==temp[j]){
                    count++;
                }
            }
            if(A[i] == B[i]){
                count++;
                temp.push_back(A[i]);
            } else {
                temp.push_back(A[i]);
                temp.push_back(B[i]);
            }
            ans.push_back(count);

        }
        return ans;  
    }

};

//were returning count, no of common including check of if the current is same

//u hae to check prev values too, in case theyre same, u have to add both values in a vector and check that instead of just ai==bi
