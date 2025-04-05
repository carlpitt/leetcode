#include <string>

#include "TreeNode.hpp"

using std::operator""s;

class Solution {
    public:
        [[nodiscard]] constexpr auto getDirections(
            const TreeNode *const root,
            const int start_value,
            const int dest_value
        ) -> std::string {
            auto start_path = std::string{};
            auto dest_path = std::string{};

            find_path(root, start_value, start_path);
            find_path(root, dest_value, dest_path);

            auto common_path_len = 0U;

            while (common_path_len < start_path.size() &&
                   common_path_len < dest_path.size() &&
                   start_path[common_path_len] == dest_path[common_path_len]) {
                ++common_path_len;
            }

            const auto start_path_len = start_path.size();
            start_path.clear();
            start_path.reserve(
                start_path_len + dest_path.size() - 2 * common_path_len
            );

            for (auto i = common_path_len; i < start_path_len; ++i) {
                start_path.push_back('U');
            }

            for (auto i = common_path_len; i < dest_path.size(); ++i) {
                start_path.push_back(dest_path[i]);
            }

            return start_path;
        }

        constexpr auto find_path(
            const TreeNode *const node,
            const int target,
            std::string &path
        ) -> bool {
            if (node == nullptr) {
                return false;
            }

            if (node->val == target) {
                return true;
            }

            path.push_back('L');

            if (find_path(node->left, target, path)) {
                return true;
            }

            path.pop_back();

            path.push_back('R');

            if (find_path(node->right, target, path)) {
                return true;
            }

            path.pop_back();

            return false;
        }
};

// works for internally immutable TreeNodes
// constexpr auto a = TreeNode{1};
// constexpr auto b = TreeNode{2, &a, nullptr};

// static_assert(Solution{}.getDirections(&b, 2, 1) == "L"s);
