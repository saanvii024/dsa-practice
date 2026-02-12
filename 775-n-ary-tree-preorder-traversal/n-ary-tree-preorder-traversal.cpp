/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root) return ans; //placing ans before this is imp, and returning ans if its null vvimp
        stack<Node*> st;
        
        st.push(root);
        while(!st.empty()){
            Node* curr = st.top(); //we are pointing to the node
            st.pop(); //remove it
            ans.push_back(curr->val); //adding the 1st root in ans
            //looping in reverse to push children in rev order
            for(int i= curr->children.size()-1; i>=0; i--){
                st.push(curr->children[i]);
            }
        }
        return ans;

        
    }
};

//approach
//stack = [1] pop1 add to answer, push children in reverse 
// stack =[4,2,3] ,they were 324
//then pop 3 add to answer and push its children in reverse again
// stack = [4,2,6,5] answer = [1,3] ... keeps on till stack =[]