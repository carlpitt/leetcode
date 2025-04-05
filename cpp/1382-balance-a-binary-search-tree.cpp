#include <vector>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] auto balanceBST(TreeNode *const root) -> TreeNode * {
            auto sorted = std::vector<TreeNode *>{};

            inorder_traverse(root, sorted);

            return sorted_to_bst(sorted, 0, sorted.size());
        }

        auto inorder_traverse(
            TreeNode *const root,
            std::vector<TreeNode *> &sorted
        ) -> void {
            if (root == nullptr) {
                return;
            }

            inorder_traverse(root->left, sorted);
            sorted.push_back(root);
            inorder_traverse(root->right, sorted);
        }

        [[nodiscard]] auto sorted_to_bst(
            const std::vector<TreeNode *> &sorted,
            const std::size_t start,
            const std::size_t end
        ) -> TreeNode * {
            if (start >= end) {
                return nullptr;
            }

            const auto mid = start + (end - start) / 2;
            const auto root = sorted[mid];
            root->left = sorted_to_bst(sorted, start, mid);
            root->right = sorted_to_bst(sorted, mid + 1, end);

            return root;
        }
};
