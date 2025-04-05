class Solution:
    def arithmeticTriplets(self, nums: list[int], diff: int) -> int:
        count = 201 * [False]
        ans = 0

        for num in nums:
            if num >= 2 * diff and count[num - diff] and count[num - 2 * diff]:
                ans += 1

            count[num] = True

        return ans
