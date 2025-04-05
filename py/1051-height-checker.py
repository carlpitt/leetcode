class Solution:
    def heightChecker(self, heights: list[int]) -> int:
        freqs = 101 * [0]
        for height in heights:
            freqs[height] += 1

        curr = 1
        ans = 0

        for height in heights:
            while freqs[curr] == 0:
                curr += 1

            if curr != height:
                ans += 1

            freqs[curr] -= 1

        return ans
