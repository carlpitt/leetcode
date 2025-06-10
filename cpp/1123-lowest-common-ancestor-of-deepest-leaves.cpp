#include <utility>

#include "TreeNode.hpp"

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto lcaDeepestLeaves(
            TreeNode *const root
        ) const noexcept -> TreeNode * {
            return dfs(root).first;
        }

    private:
        [[nodiscard]] constexpr auto dfs(TreeNode *const root) const noexcept
            -> std::pair<TreeNode *, uint> {
            if (root == nullptr) {
                return {nullptr, 0};
            }

            const auto left = dfs(root->left);
            const auto right = dfs(root->right);

            if (left.second > right.second) {
                return {left.first, left.second + 1};
            }

            if (left.second < right.second) {
                return {right.first, right.second + 1};
            }

            return {root, left.second + 1};
        }
};
