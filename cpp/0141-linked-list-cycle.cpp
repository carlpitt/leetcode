#include "ListNode.hpp"

class Solution {
    public:
        [[nodiscard]] auto hasCycle(const ListNode *head) const noexcept
            -> bool {
            const auto *hare = head;

            while (hare != nullptr && hare->next != nullptr) {
                head = head->next;
                hare = hare->next->next;

                if (head == hare) {
                    return true;
                }
            }

            return false;
        }
};
