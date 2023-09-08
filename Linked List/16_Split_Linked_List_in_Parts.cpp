/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //Finding the length of the linked list
        ListNode* curr = head;
        int L = 0;
        while(curr){
            L++;
            curr = curr->next;
        }

        int eachBucketNodes = L/k;
        int extraNodes = L%k;

        vector<ListNode*> result(k, NULL);

        curr = head;
        ListNode* prev = NULL;

        for(int i = 0; i < k; i++){
            result[i] = curr;
            for(int cnt = 1; cnt <= eachBucketNodes + (extraNodes > 0 ? 1 : 0); cnt++){
                prev = curr;
                curr = curr->next;
            }
            if(prev != NULL) prev->next = NULL;
            extraNodes--;
        }
        return result;
    }
};