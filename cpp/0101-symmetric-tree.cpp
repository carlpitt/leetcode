#include <queue>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] auto isSymmetric(TreeNode *const root) const -> bool {
            // return root == nullptr || is_symmetric_helper(root->left,
            // root->right);

            auto q = std::queue<TreeNode *>{};

            q.push(root);
            q.push(root);

            while (!q.empty()) {
                const auto t1 = q.front();

                q.pop();

                const auto t2 = q.front();

                q.pop();

                if (t1 == nullptr || t2 == nullptr) {
                    if (t1 == nullptr && t2 == nullptr) {
                        continue;
                    }

                    return false;
                }
                if (t1->val != t2->val) {
                    return false;
                }

                q.push(t1->left);
                q.push(t2->right);
                q.push(t1->right);
                q.push(t2->left);
            }

            return true;
        }

        // private:
        //     [[nodiscard]] constexpr auto
        //     is_symmetric_helper(TreeNode* const left, TreeNode* const right)
        //     const
        //         -> bool {
        //         if (left == nullptr || right == nullptr) {
        //             return left == right;
        //         }

        //         return left->val == right->val &&
        //                is_symmetric_helper(left->left, right->right) &&
        //                is_symmetric_helper(left->right, right->left);
        //     }
};
