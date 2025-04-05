class Solution:
    def romanToInt(self, s: str) -> int:
        symbol_to_value = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000,
        }

        ans = 0
        prev = max(symbol_to_value.values()) + 1

        for c in s:
            curr = symbol_to_value[c]
            if curr > prev:
                ans -= 2 * prev
            ans += curr
            prev = curr

        return ans
