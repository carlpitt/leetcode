class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        left = 0
        unique = set[str]()

        for right_c in s:
            # decrement until current window is valid, i.e. no repeating char
            while right_c in unique:
                unique.remove(s[left])

                left += 1

            unique.add(right_c)

            ans = max(ans, len(unique))

        return ans
