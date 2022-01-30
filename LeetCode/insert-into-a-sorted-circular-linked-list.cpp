
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        } else {
            Node* temp = head;
            while (1) {
                if (head->val < head->next->val) {
                    if (head->val <= insertVal && insertVal <= head->next->val)
                        break;
                }
                else if (head->val > head->next->val) {
                    if (head->next->val <= insertVal && insertVal <= head->val)
                        if (head->val < head->next->next->val)
                            break;
                    if (head->next->val > insertVal && insertVal < head->val)
                        break;
                    if (head->val < insertVal && insertVal > head->next->val)
                        break;
                } else if (head->val == head->next->val && head->next->val == head->next->next->val) {
                    break;
                }
                /*
                 while (head->next && head->val != head->next->val)
                if ((head->val <= insertVal && insertVal <= head->next->val)
                   || (head->val >= insertVal && insertVal >= head->next->val 
                       && head->next->val < head->val))
                    break;
                */
                head = head->next;
            }

            Node* node = new Node(insertVal);
            node->next = head->next;
            head->next = node;

            if (!node->next)
                node->next = temp;
            return temp;
        }
    }
};