class Solution:
    def longestPalindrome(self, s: str) -> int:
        non_paired_letters: set[str] = set()
        for c in s:
            if c in non_paired_letters:
                non_paired_letters.remove(c)
            else:
                non_paired_letters.add(c)
        return len(s) - len(non_paired_letters) + (len(non_paired_letters) > 0)
