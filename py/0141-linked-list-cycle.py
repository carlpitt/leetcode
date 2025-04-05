from typing import TypeVar, Generic

T = TypeVar("T")


# Definition for singly-linked list.
class ListNode(Generic[T]):
    def __init__(self, x: T) -> None:
        self.val = x
        self.next: ListNode[T] | None = None


class Solution:
    def hasCycle(self, head: ListNode[T] | None) -> bool:
        hare = head
        while hare is not None and hare.next is not None:
            assert head is not None
            head = head.next
            hare = hare.next.next
            if head is hare:
                return True
        return False
