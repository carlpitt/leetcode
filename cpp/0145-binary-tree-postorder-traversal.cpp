#include <algorithm>
#include <vector>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] constexpr auto postorderTraversal(TreeNode *const root)
            -> std::vector<int> {
            auto ans = std::vector<int>{};

            // helper(root, ans);

            auto curr = root;

            while (curr != nullptr) {
                if (curr->right == nullptr) {
                    ans.push_back(curr->val);

                    curr = curr->left;

                    continue;
                }

                auto pre = curr->right;

                while (pre->left != nullptr && pre->left != curr) {
                    pre = pre->left;
                }

                if (pre->left == nullptr) {
                    ans.push_back(curr->val);

                    pre->left = curr;
                    curr = curr->right;
                } else {
                    pre->left = nullptr;
                    curr = curr->left;
                }
            }

            std::ranges::reverse(ans);

            return ans;
        }

        constexpr auto helper(const TreeNode *const root, std::vector<int> &ans)
            -> void {
            if (root == nullptr) {
                return;
            }

            helper(root->left, ans);
            helper(root->right, ans);

            ans.push_back(root->val);
        }
};
