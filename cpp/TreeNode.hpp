// Definition for a binary tree node.
struct [[nodiscard]] TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;

        explicit constexpr TreeNode(const int x = 0) noexcept :
            val{x}, left{nullptr}, right{nullptr} {}

        constexpr TreeNode(
            const int x,
            TreeNode *const lef,
            TreeNode *const rig
        ) noexcept :
            val{x}, left{lef}, right{rig} {}
};
