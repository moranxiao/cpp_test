class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;
        while(cur)
        {
            Node* node = new Node(cur->val);
            Node* next = cur->next;
            cur->next = node;
            node->next = next;
            cur = next;
        }
        cur = head;
        while(cur)
        {
            
            cur->next->random = cur->random ? cur->random->next : nullptr;
            cur = cur->next->next;
        }
        Node* newHead = head ? head->next : nullptr;
        cur = head;
        while(cur)
        {
            Node* next = cur->next->next;
            cur->next->next = next ? next->next : nullptr;
            cur->next = next;
            cur = next;
        }
        return newHead;
    }
};