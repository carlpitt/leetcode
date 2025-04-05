# Definition for singly-linked list.


class ListNode:
    def __init__(self, val: int = 0, next: "ListNode | None" = None):
        self.val = val
        self.next = next


class Solution:
    def oddEvenList(self, head: ListNode | None) -> ListNode | None:
        if head is None:
            return None

        odd = head
        even = head.next
        even_head = even

        while even is not None and even.next is not None:
            assert odd.next is not None
            odd.next = odd.next.next
            even.next = even.next.next

            assert odd.next is not None
            odd = odd.next
            even = even.next

        odd.next = even_head

        return head
