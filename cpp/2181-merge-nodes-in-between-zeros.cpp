#include "ListNode.hpp"

class Solution {
    public:
        [[nodiscard]] constexpr auto mergeNodes(
            ListNode *const head
        ) const noexcept -> ListNode * {
            for (auto curr = head->next; curr != nullptr; curr = curr->next) {
                const auto *end = curr;
                auto sum = 0;

                while (end->val != 0) {
                    sum += end->val;
                    end = end->next;
                }

                curr->val = sum;
                curr->next = end->next;
            }

            return head->next;
        }
};
