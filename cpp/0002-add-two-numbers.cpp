// Definition for singly-linked list.
struct ListNode {
        int val;
        ListNode *next;

        ListNode() : val{0}, next{nullptr} {}

        explicit ListNode(const int x) : val{x}, next{nullptr} {}

        ListNode(const int x, ListNode *const next) : val{x}, next{next} {}
};

class Solution {
    public:
        [[nodiscard]] auto addTwoNumbers(const ListNode *l1, const ListNode *l2)
            -> ListNode * {
            auto dummy_head = ListNode{0};
            auto curr = &dummy_head;
            auto carry = 0;
            while (l1 != nullptr || l2 != nullptr || carry > 0) {
                if (l1 != nullptr) {
                    carry += l1->val;
                    l1 = l1->next;
                }
                if (l2 != nullptr) {
                    carry += l2->val;
                    l2 = l2->next;
                }

                curr->next = new ListNode{carry % 10};
                curr = curr->next;

                carry /= 10;
            }

            return dummy_head.next;
        }
};
