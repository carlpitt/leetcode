from collections import Counter


class Solution:
    def isNStraightHand(self, hand: list[int], group_size: int) -> bool:
        counts = Counter(hand)

        for start in sorted(counts):
            start_freq = counts[start]
            if start_freq > 0:
                for i in range(start, start + group_size):
                    counts[i] -= start_freq
                    if counts[i] < 0:
                        return False

        return True
