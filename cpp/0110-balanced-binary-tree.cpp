#include <algorithm>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] constexpr auto isBalanced(TreeNode *const root) const
            -> bool {
            return dfs_height(root) != -1;
        }

    private:
        [[nodiscard]] constexpr auto dfs_height(TreeNode *const root) const
            -> int {
            if (root == nullptr) {
                return 0;
            }

            const auto left_height = dfs_height(root->left);
            if (left_height == -1) {
                return -1;
            }

            const auto right_height = dfs_height(root->right);
            if (right_height == -1 ||
                std::abs(left_height - right_height) > 1) {
                return -1;
            }

            return std::max(left_height, right_height) + 1;
        }
};
