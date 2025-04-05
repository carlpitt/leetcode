class Solution:
    def checkSubarraySum(self, nums: list[int], k: int) -> bool:
        totals = {0: -1}
        total = 0
        for i, n in enumerate(nums):
            # k != 0 check not needed
            total = (total + n) % k
            if total in totals:
                if i - totals[total] > 1:
                    return True
            else:
                totals[total] = i
        return False
