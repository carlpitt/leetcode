#include <array>
#include <vector>

#include "ListNode.hpp"

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto modifiedList(
            const std::vector<int> &nums,
            ListNode *const head
        ) -> ListNode * {
            // const auto num_set = std::unordered_set<int>{nums.begin(),
            // nums.end()};

            // auto num_set = std::bitset<100'001>{};
            auto num_set = std::array<bool, 100'001>{};

            for (const auto num : nums) {
                num_set[static_cast<uint>(num)] = true;
            }

            auto dummy = ListNode{0, head};
            auto curr = &dummy;

            while (curr->next != nullptr) {
                if (num_set[static_cast<uint>(curr->next->val)]) {
                    curr->next = curr->next->next;
                } else {
                    curr = curr->next;
                }
            }

            return dummy.next;
        }
};
