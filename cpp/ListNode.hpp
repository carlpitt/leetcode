// Definition for singly-linked list.
struct [[nodiscard]] ListNode {
        int val;
        ListNode *next;

        explicit constexpr ListNode(
            const int x = 0,
            ListNode *const n = nullptr
        ) noexcept :
            val{x}, next{n} {}
};
