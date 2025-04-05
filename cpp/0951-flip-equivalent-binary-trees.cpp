#include <array>
#include <stack>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] constexpr auto flipEquiv(
            TreeNode *const root1,
            TreeNode *const root2
        ) const noexcept -> bool {
            // // 1. recursion (top-down traversal)
            // // O(n)
            // // O(n)
            // return (root1 == nullptr && root2 == nullptr) ||
            //        (root1 != nullptr && root2 != nullptr &&
            //         root1->val == root2->val &&
            //         // (no swap) || swap
            //         ((flipEquiv(root1->left, root2->left) &&
            //           flipEquiv(root1->right, root2->right)) ||
            //          (flipEquiv(root1->left, root2->right) &&
            //           flipEquiv(root1->right, root2->left))));

            // // 2. iterative dfs (using stack)
            // // O(n)
            // // O(n)
            // auto stack =
            //     std::stack<std::array<const TreeNode*, 2>>{{{root1, root2}}};

            // while (!stack.empty()) {
            //     const auto [node1, node2] = stack.top();

            //     stack.pop();

            //     if (node1 == nullptr && node2 == nullptr) {
            //         continue;
            //     }

            //     if (node1 == nullptr || node2 == nullptr ||
            //         node1->val != node2->val) {
            //         return false;
            //     }

            //     if (check_node_vals(node1->left, node2->left) &&
            //         check_node_vals(node1->right, node2->right)) {
            //         stack.push({node1->left, node2->left});
            //         stack.push({node1->right, node2->right});

            //         continue;
            //     }

            //     if (check_node_vals(node1->left, node2->right) &&
            //         check_node_vals(node1->right, node2->left)) {
            //         stack.push({node1->left, node2->right});
            //         stack.push({node1->right, node2->left});

            //         continue;
            //     }

            //     return false;
            // }

            // return true;

            // 3. canonical forms
            // O(n)
            // O(n)
            find_canonical_form(root1);
            find_canonical_form(root2);

            return are_equiv(root1, root2);
        }

    private:
        [[nodiscard]] constexpr auto check_node_vals(
            const TreeNode *const node1,
            const TreeNode *const node2
        ) const noexcept -> bool {
            return (node1 == nullptr && node2 == nullptr) ||
                   (node1 != nullptr && node2 != nullptr &&
                    node1->val == node2->val);
        }

        constexpr auto find_canonical_form(TreeNode *const root) const noexcept
            -> void {
            if (root == nullptr) {
                return;
            }

            find_canonical_form(root->left);
            find_canonical_form(root->right);

            if (root->right == nullptr) {
                return;
            }

            if (root->left == nullptr) {
                root->left = root->right;
                root->right = nullptr;

                return;
            }

            const auto left = root->left;
            const auto right = root->right;

            if (left->val > right->val) {
                root->left = right;
                root->right = left;
            }
        }

        [[nodiscard]] constexpr auto are_equiv(
            const TreeNode *const root1,
            const TreeNode *const root2
        ) const noexcept -> bool {
            return (root1 == nullptr && root2 == nullptr) ||
                   (root1 != nullptr && root2 != nullptr &&
                    root1->val == root2->val &&
                    are_equiv(root1->left, root2->left) &&
                    are_equiv(root1->right, root2->right));
        }
};
