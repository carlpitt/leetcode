#include <queue>
#include <stack>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] constexpr auto invertTree(
            TreeNode *const root
        ) const noexcept -> TreeNode * {
            // // 1. recursive dfs
            // //
            // //
            // if (root == nullptr) {
            //     return nullptr;
            // }

            // // root->left, root->right = invertTree(root->right),
            // // invertTree(root->left);
            // const auto left = root->left;
            // root->left = invertTree(root->right);
            // root->right = invertTree(left);

            // return root;

            // // 2. iterative dfs
            // //
            // //
            // if (root == nullptr) {
            //     return nullptr;
            // }

            // auto stack = std::stack<TreeNode*>{{root}};

            // while (!stack.empty()) {
            //     const auto curr = stack.top();

            //     stack.pop();

            //     std::swap(curr->left, curr->right);

            //     if (curr->left != nullptr) {
            //         stack.push(curr->left);
            //     }

            //     if (curr->right != nullptr) {
            //         stack.push(curr->right);
            //     }
            // }

            // return root;

            // 3. bfs (level order traversal)
            //
            //
            if (root == nullptr) {
                return nullptr;
            }

            auto queue = std::queue<TreeNode *>{{root}};

            while (!queue.empty()) {
                const auto curr = queue.front();

                queue.pop();

                std::swap(curr->left, curr->right);

                if (curr->left != nullptr) {
                    queue.push(curr->left);
                }

                if (curr->right != nullptr) {
                    queue.push(curr->right);
                }
            }

            return root;
        }
};
