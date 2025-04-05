from typing import TypeVar, Generic

T = TypeVar("T")


# Definition for singly-linked list.
class ListNode(Generic[T]):
    def __init__(self, x: T) -> None:
        self.val = x
        self.next: ListNode[T] | None = None


class Solution:
    def deleteNode(self, node: ListNode[T]) -> None:
        assert node.next is not None
        node.val = node.next.val
        node.next = node.next.next
