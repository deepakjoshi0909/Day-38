class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;

        unordered_map<Node*, Node*> ans;

        Node* temp = head;

        while (temp) {
            ans[temp] = new Node(temp->val);

            temp = temp->next;
        }

        temp = head;

        while (temp) {
            ans[temp]->next = ans[temp->next];
            ans[temp]->random = ans[temp->random];

            temp = temp->next;
        }

        return ans[head];
    }
};
