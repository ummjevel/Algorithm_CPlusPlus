struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* end = head;
        ListNode* newTail = head;
        ListNode* newHead;
        int cnt = 1;
        while(end->next) {
            end = end->next;
            cnt++;
        }
        k = k % cnt;
        while(cnt - k - 1 != 0) {
            newTail = newTail->next;
            cnt--;
        }  
        
        end->next = head;
        newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
