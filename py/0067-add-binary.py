class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # return bin(int(a, 2) + int(b, 2))[2:]

        # binary result bits
        ans: list[str] = []
        # pointers
        i = len(a) - 1
        j = len(b) - 1
        carry = 0
        # loop while there are bits to process or a carry
        while i >= 0 or j >= 0 or carry > 0:
            if i >= 0:
                carry += int(a[i])
                i -= 1
            if j >= 0:
                carry += int(b[j])
                j -= 1

            # append current bit to result
            ans.append(str(carry % 2))
            # update carry
            carry //= 2

        # reverse list and convert to str
        return "".join(ans)[::-1]
