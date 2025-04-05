# Definition for singly-linked list.


class ListNode:
    def __init__(self, val: int = 0, next_node: "ListNode | None" = None) -> None:
        self.val = val
        self.next = next_node


class Solution:
    def addTwoNumbers(
        self, l1: ListNode | None, l2: ListNode | None
    ) -> ListNode | None:
        dummy = ListNode(0)
        curr = dummy
        carry = 0
        while l1 is not None or l2 is not None or carry > 0:
            s = carry
            if l1 is not None:
                s += l1.val
                l1 = l1.next
            if l2 is not None:
                s += l2.val
                l2 = l2.next
            carry, out = divmod(s, 10)

            curr.next = ListNode(out)
            curr = curr.next

        return dummy.next
