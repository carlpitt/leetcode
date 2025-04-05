#include <array>
#include <stack>
#include <string>

class Solution {
    public:
        [[nodiscard]] auto reverseParentheses(const std::string &s)
            -> std::string {
            const auto n = s.size();
            auto opened = std::stack<unsigned>{};
            std::array<unsigned, 2000> pair;

            for (auto i = 0U; i < n; ++i) {
                if (s[i] == '(')
                    opened.push(i);
                if (s[i] == ')') {
                    const auto j = opened.top();
                    opened.pop();
                    pair[i] = j;
                    pair[j] = i;
                }
            }

            auto ans = std::string{};
            auto i = 0U;
            auto forward = true;

            while (i < n) {
                if (s[i] == '(' || s[i] == ')') {
                    i = pair[i];
                    forward = !forward;
                } else {
                    ans += s[i];
                }

                i += static_cast<unsigned>(2 * forward - 1);
            }

            return ans;
        }
};
