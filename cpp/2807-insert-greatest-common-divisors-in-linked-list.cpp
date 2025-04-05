#include <numeric>
#include <utility>

#include "ListNode.hpp"

class Solution {
    public:
        [[nodiscard]] constexpr auto insertGreatestCommonDivisors(
            ListNode *const head
        ) const noexcept -> ListNode * {
            auto node_a = head;

            while (node_a->next != nullptr) {
                const auto node_b = node_a->next;
                node_a->next =
                    new ListNode{std::gcd(node_a->val, node_b->val), node_b};
                node_a = node_b;
            }

            return head;
        }

    private:
        [[nodiscard]] constexpr auto gcd(int a, int b) const noexcept -> int {
            while (b != 0) {
                a = std::exchange(b, a % b);
            }

            return a;
        }
};
