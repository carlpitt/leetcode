#include <vector>

#include "ListNode.hpp"
#include "TreeNode.hpp"

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto isSubPath(
            const ListNode *head,
            const TreeNode *const root
        ) const -> bool {
            // return root != nullptr &&
            //        (dfs(head, root) || isSubPath(head, root->left) ||
            //         isSubPath(head, root->right));

            auto pattern = std::vector{head->val};
            auto prefix_table = std::vector{0U};
            auto i = 0U;
            head = head->next;

            while (head != nullptr) {
                while (i > 0 && head->val != pattern[i]) {
                    i = prefix_table[i - 1];
                }

                if (head->val == pattern[i]) {
                    ++i;
                }

                pattern.push_back(head->val);
                prefix_table.push_back(i);

                head = head->next;
            }

            return search(root, pattern, prefix_table, 0);
        }

    private:
        [[nodiscard]] constexpr auto dfs(
            const ListNode *const head,
            const TreeNode *const root
        ) const noexcept -> bool {
            return head == nullptr ||
                   (root != nullptr && head->val == root->val &&
                    (dfs(head->next, root->left) || dfs(head->next, root->right)
                    ));
        }

        [[nodiscard]] constexpr auto search(
            const TreeNode *const root,
            const std::vector<int> &pattern,
            const std::vector<uint> &prefix_table,
            uint i
        ) const noexcept -> bool {
            if (root == nullptr) {
                return false;
            }

            while (i > 0 && root->val != pattern[i]) {
                i = prefix_table[i - 1];
            }

            if (root->val == pattern[i]) {
                ++i;
            }

            return i == pattern.size() ||
                   search(root->left, pattern, prefix_table, i) ||
                   search(root->right, pattern, prefix_table, i);
        }
};
