#include <iostream>

#include "ListNode.hpp"

class Solution {
    public:
        constexpr auto deleteNode(ListNode *const node) const noexcept -> void {
            node->val = node->next->val;
            node->next = node->next->next;
        }
};

auto main() -> int {
    auto node2 = ListNode{3};
    auto node1 = ListNode{2, &node2};
    Solution{}.deleteNode(&node1);
    std::cout << node1.val << '\n';
    std::cout << node1.next << '\n';
}
