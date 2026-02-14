class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* dummy = new ListNode(0); //as we might also need to delete the head, we need to store it somewhere
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while(curr != NULL){
            if(curr->val == val){
                prev->next = curr->next; //just skip curr and move to the next curr
            }else{
                prev = curr;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
