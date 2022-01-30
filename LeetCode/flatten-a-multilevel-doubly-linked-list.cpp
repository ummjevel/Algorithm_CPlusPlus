#include <stack>

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        stack<Node*> st;
        while(head) {
            if (head->child) {
                if(head->next)
                    st.push(head->next);
                
                head->next = head->child;
                head->next->prev = head;
                head->child = NULL;
            }
            if (!(head->next) && !st.empty()) {
                head->next = st.top();
                st.pop();
                head->next->prev = head;
            }
            head = head->next;
        }
        return temp;
    }
};

/*
Node* temp = head;
        stack<Node*> st;
        while(head != NULL) {
            if(head->child != NULL) {
                if(head->next != NULL)
                    st.push(head->next);
                head->next = head->child;
                head->next->prev = head;
                head->child = NULL;
            }
            if( head->next == NULL && !st.empty()){
                head->next = st.top();
                st.pop();
                head->next->prev = head;
            }
            head = head->next;
        }
        return temp;

*/

/*
        Node *node1 = head;
        Node *node2 = head;
        
        while(node1 && node2) {
            // null에서 숫자가 나올 때까지
            while(node1) {
                node1 = node1->next;
            }
            // 숫자에서 null 이 나올 때까지 
            while(!node1) {
                node2 = node2->next;
                node1 = node1->next;
            }
            node1->child = node2;
            
            // 한바퀴
        }
        return head;
        */
        