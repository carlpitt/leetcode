class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        # get first and last strs alphabetically
        min_s = min(strs)
        max_s = max(strs)

        # find common prefix between first and last
        length = min(len(min_s), len(max_s))
        for i in range(length):
            if min_s[i] != max_s[i]:
                return min_s[:i]

        return min_s[:length]
