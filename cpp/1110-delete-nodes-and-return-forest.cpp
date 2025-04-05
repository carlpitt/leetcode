#include <queue>
#include <unordered_set>
#include <vector>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] auto delNodes(
            TreeNode *const root,
            const std::vector<int> &to_delete
        ) -> std::vector<TreeNode *> {
            const auto to_delete_set =
                std::unordered_set<int>{to_delete.begin(), to_delete.end()};
            auto ans = std::vector<TreeNode *>{};

            // dfs
            // if (const auto* const new_root = dfs(root, to_delete_set, ans);
            //     new_root != nullptr) {
            //     ans.push_back(root);
            // }

            // bfs
            auto queue = std::queue<TreeNode *>{{root}};

            while (!queue.empty()) {
                const auto node = queue.front();
                queue.pop();

                if (node->left != nullptr) {
                    queue.push(node->left);
                    if (to_delete_set.contains(node->left->val)) {
                        node->left = nullptr;
                    }
                }
                if (node->right != nullptr) {
                    queue.push(node->right);
                    if (to_delete_set.contains(node->right->val)) {
                        node->right = nullptr;
                    }
                }

                if (to_delete_set.contains(node->val)) {
                    if (node->left != nullptr) {
                        ans.push_back(node->left);
                    }
                    if (node->right != nullptr) {
                        ans.push_back(node->right);
                    }
                }
            }

            if (!to_delete_set.contains(root->val)) {
                ans.push_back(root);
            }

            return ans;
        }

        [[nodiscard]] constexpr auto dfs(
            TreeNode *const node,
            const std::unordered_set<int> &to_delete_set,
            std::vector<TreeNode *> &forests
        ) -> TreeNode * {
            if (node->left != nullptr) {
                node->left = dfs(node->left, to_delete_set, forests);
            }
            if (node->right != nullptr) {
                node->right = dfs(node->right, to_delete_set, forests);
            }

            if (to_delete_set.contains(node->val)) {
                if (node->left != nullptr) {
                    forests.push_back(node->left);
                }
                if (node->right != nullptr) {
                    forests.push_back(node->right);
                }

                return nullptr;
            }

            return node;
        }
};
