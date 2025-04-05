#include <queue>

#include "TreeNode.hpp"

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto isCousins(
            const TreeNode *const root,
            const int x,
            const int y
        ) const noexcept -> bool {
            // // dfs
            // //
            // //
            // auto depth = 0;
            // auto parent = 0;

            // return dfs(root, x, y, 0, -1, depth, parent);

            // bfs
            //
            //
            auto queue = std::queue<const TreeNode *>{{root}};

            while (!queue.empty()) {
                const auto n = queue.size();
                auto x_found = false;
                auto y_found = false;

                for (auto i = 0U; i < n; ++i) {
                    const auto *const curr = queue.front();

                    queue.pop();

                    if (curr->val == x) {
                        x_found = true;
                    } else if (curr->val == y) {
                        y_found = true;
                    }

                    if (curr->left != nullptr && curr->right != nullptr &&
                        ((curr->left->val == x && curr->right->val == y) ||
                         (curr->left->val == y && curr->right->val == x))) {
                        return false;
                    }

                    if (curr->left != nullptr) {
                        queue.push(curr->left);
                    }

                    if (curr->right != nullptr) {
                        queue.push(curr->right);
                    }
                }

                if (x_found && y_found) {
                    return true;
                }

                if (x_found || y_found) {
                    return false;
                }
            }

            return false;
        }

    private:
        [[nodiscard]] constexpr auto dfs(
            const TreeNode *const root,
            const int x,
            const int y,
            const int curr_depth,
            const int curr_parent,
            int &depth,
            int &parent
        ) const noexcept -> bool {
            if (root == nullptr || (parent != 0 && curr_depth > depth)) {
                return false;
            }

            if (root->val == x || root->val == y) {
                if (parent == 0) {
                    parent = curr_parent;
                    depth = curr_depth;

                    return false;
                }

                return parent != curr_parent && depth == curr_depth;
            }

            return dfs(root->left,
                       x,
                       y,
                       curr_depth + 1,
                       root->val,
                       depth,
                       parent) ||
                   dfs(root->right,
                       x,
                       y,
                       curr_depth + 1,
                       root->val,
                       depth,
                       parent);
        }
};
