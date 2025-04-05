from collections import Counter


class Solution:
    def isPossibleDivide(self, nums: list[int], k: int) -> bool:
        counts = Counter(nums)

        for start in sorted(counts):
            start_freq = counts[start]
            if start_freq > 0:
                for i in range(start, start + k):
                    counts[i] -= start_freq
                    if counts[i] < 0:
                        return False

        return True
