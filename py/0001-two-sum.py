class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        d = dict[int, int]()

        for i, n in enumerate(nums):
            diff = target - n
            if diff in d:
                return [d[diff], i]
            d[n] = i

        return []
