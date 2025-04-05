#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "TreeNode.hpp"

class Solution {
    public:
        [[nodiscard]] auto createBinaryTree(
            const std::vector<std::vector<int>> &descriptions
        ) -> TreeNode * {
            auto node_map = std::unordered_map<int, TreeNode *>{};
            auto children = std::unordered_set<int>{};

            for (const auto &d : descriptions) {
                const auto parent_val = d[0];
                const auto child_val = d[1];
                const auto is_left = d[2];

                auto &parent_node = node_map[parent_val];
                if (parent_node == nullptr) {
                    parent_node = new TreeNode{parent_val};
                }

                auto &child_node = node_map[child_val];
                if (child_node == nullptr) {
                    child_node = new TreeNode{child_val};
                }

                if (is_left == 1) {
                    parent_node->left = child_node;
                } else /* is_left == 0 */ {
                    parent_node->right = child_node;
                }

                children.insert(child_val);
            }

            for (const auto &[val, node] : node_map) {
                if (!children.contains(val)) {
                    return node;
                }
            }

            return nullptr;
        }
};
