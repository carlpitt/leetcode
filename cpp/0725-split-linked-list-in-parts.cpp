#include <utility>
#include <vector>

#include "ListNode.hpp"

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto splitListToParts(
            ListNode *head,
            const uint k
        ) const noexcept -> std::vector<ListNode *> {
            const auto n = [head]() {
                auto ans = 0U;

                for (const auto *curr = head; curr != nullptr;
                     curr = curr->next) {
                    ++ans;
                }

                return ans;
            }();

            auto ans = std::vector<ListNode *>(k);

            for (auto i = 0U; i < std::min(k, n); ++i) {
                ans[i] = head;

                for (auto j = 0U; j < n / k + (i < n % k) - 1; ++j) {
                    head = head->next;
                }

                head = std::exchange(head->next, nullptr);
            }

            return ans;
        }
};
