class Solution:
    def integerReplacement(self, n: int) -> int:
        ans = 0
        while n > 1:
            if n % 2 == 0:
                n //= 2
            elif n == 3 or (n - 1) % 4 == 0:
                n -= 1
            else:
                n += 1
            ans += 1

        return ans
