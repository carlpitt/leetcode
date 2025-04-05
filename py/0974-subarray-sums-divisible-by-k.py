class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        prefix_sum = 0
        # freqs = defaultdict(int)
        freqs = [0] * k
        freqs[0] = 1
        ans = 0
        for n in nums:
            prefix_sum = (prefix_sum + n) % k
            ans += freqs[prefix_sum]
            freqs[prefix_sum] += 1

        return ans
