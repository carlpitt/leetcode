#include <numeric>
#include <queue>
#include <vector>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] constexpr auto largestValues(
            const TreeNode *const root
        ) const noexcept -> std::vector<int> {
            // 1. breadth first search (bfs)
            // O(n)
            // O(n)
            auto ans = std::vector<int>{};

            if (root == nullptr) {
                return ans;
            }

            auto q = std::queue<const TreeNode *>{{root}};

            while (!q.empty()) {
                const auto len = q.size();
                auto curr_max = std::numeric_limits<int>::min();

                for (auto i = 0U; i < len; ++i) {
                    const auto *const node = q.front();

                    q.pop();

                    curr_max = std::max(curr_max, node->val);

                    if (node->left != nullptr) {
                        q.push(node->left);
                    }

                    if (node->right != nullptr) {
                        q.push(node->right);
                    }
                }

                ans.push_back(curr_max);
            }

            return ans;
        }
};
