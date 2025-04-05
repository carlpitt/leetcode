#include <array>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] constexpr auto
        countPairs(const TreeNode *const root, const unsigned distance) -> int {
            return post_order(root, distance)[11];
        }

        [[nodiscard]] constexpr auto post_order(
            const TreeNode *const node,
            const unsigned distance
        ) -> std::array<int, 12> {
            auto ans = std::array<int, 12>{};

            if (node == nullptr) {
                return ans;
            }
            if (node->left == nullptr && node->right == nullptr) {
                ans[0] = 1;

                return ans;
            }

            const auto left = post_order(node->left, distance);
            const auto right = post_order(node->right, distance);

            // max distance is 10
            for (auto i = 0U; i < 10; ++i) {
                ans[i + 1] = left[i] + right[i];
            }

            ans[11] = left[11] + right[11];

            for (auto d1 = 0U; d1 <= distance; ++d1) {
                for (auto d2 = 0U; d1 + d2 + 2 <= distance; ++d2) {
                    ans[11] += left[d1] * right[d2];
                }
            }

            return ans;
        }
};
