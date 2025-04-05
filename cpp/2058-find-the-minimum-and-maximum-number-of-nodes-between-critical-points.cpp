#include <limits>
#include <vector>

#include "ListNode.hpp"

class Solution {
    public:
        [[nodiscard]] auto nodesBetweenCriticalPoints(const ListNode *head)
            -> std::vector<int> {
            auto prev_val = head->val;
            int first;
            auto last = 0;
            auto i = 1;
            auto min_d = std::numeric_limits<int>::max();

            head = head->next;

            while (head->next != nullptr) {
                if (std::max(prev_val, head->next->val) < head->val ||
                    std::min(prev_val, head->next->val) > head->val) {
                    if (last == 0) {
                        first = i;
                    } else {
                        min_d = std::min(min_d, i - last);
                    }

                    last = i;
                }

                prev_val = head->val;
                head = head->next;
                ++i;
            }

            if (min_d == std::numeric_limits<int>::max()) {
                return std::vector<int>{-1, -1};
            }

            return std::vector<int>{min_d, last - first};
        }
};
