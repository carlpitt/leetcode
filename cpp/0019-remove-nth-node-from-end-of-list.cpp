#include "ListNode.hpp"

class Solution {
    public:
        [[nodiscard]] auto removeNthFromEnd(ListNode *const head, const int n)
            const -> ListNode * {
            const auto *fast = head;

            for (auto i = 0; i < n; ++i) {
                fast = fast->next;
            }

            if (fast == nullptr) {
                return head->next;
            }

            auto slow = head;

            while (fast->next != nullptr) {
                fast = fast->next;
                slow = slow->next;
            }

            slow->next = slow->next->next;

            return head;
        }
};
