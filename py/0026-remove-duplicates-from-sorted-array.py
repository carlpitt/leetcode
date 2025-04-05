class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        ans = 1

        for i in range(1, len(nums)):
            if nums[i - 1] != nums[i]:
                nums[ans] = nums[i]
                ans += 1

        return ans
