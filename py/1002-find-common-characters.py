from collections import Counter


class Solution:
    def commonChars(self, words: list[str]) -> list[str]:
        common = Counter(words[0])

        for word in words[1:]:
            common &= Counter(word)

        ans: list[str] = []

        for c, freq in common.items():
            ans.extend(freq * [c])

        return ans
