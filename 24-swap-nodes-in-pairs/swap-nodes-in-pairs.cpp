class Solution {
public:

    void swapp(ListNode* head){

        if(head == NULL || head->next == NULL)
            return;

        int temp = head->val;
        head->val = head->next->val;
        head->next->val = temp;
    }

    ListNode* swapPairs(ListNode* head) {

        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL){

            swapp(temp);

            temp = temp->next->next;
        }

        return head;
    }
};