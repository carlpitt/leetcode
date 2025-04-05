class Solution:
    def decodeString(self, s: str) -> str:
        curr_s = ""
        curr_n = 0
        stack: list[int | str] = []
        for c in s:
            if c.isalpha():
                curr_s += c
            elif c.isdigit():
                curr_n = 10 * curr_n + int(c)
            elif c == "[":
                stack.append(curr_s)
                stack.append(curr_n)
                curr_s = ""
                curr_n = 0
            else:
                # c is "]"
                n = stack.pop()
                assert isinstance(n, int)
                prev_s = stack.pop()
                assert isinstance(prev_s, str)
                curr_s = prev_s + n * curr_s

        return curr_s
