from collections import defaultdict


class TrieNode:
    def __init__(self) -> None:
        self.children: defaultdict[str, TrieNode] = defaultdict(TrieNode)
        self.is_end = False


class Solution:
    def replaceWords(self, dictionary: list[str], sentence: str) -> str:
        root = TrieNode()
        for word in dictionary:
            node = root
            for c in word:
                node = node.children[c]
            node.is_end = True

        def replace(word: str) -> str:
            node = root
            for i, c in enumerate(word):
                if node.is_end:
                    return word[:i]
                node = node.children[c]
            return word

        return " ".join(replace(word) for word in sentence.split())
