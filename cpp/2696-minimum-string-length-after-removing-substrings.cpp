#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minLength(std::string &s) const noexcept
            -> uint {
            // // string replace/erase
            // // O(n^2)
            // // O(1)

            // auto out = false;

            // while (!out) {
            //     out = true;

            //     for (auto i = 0U; i + 1 < s.size(); ++i) {
            //         if ((s[i] == 'A' && s[i + 1] == 'B') ||
            //             (s[i] == 'C' && s[i + 1] == 'D')) {
            //             s.erase(i, 2);

            //             out = false;

            //             break;
            //         }
            //     }
            // }

            // return s.size();

            // // stack
            // // O(n)
            // // O(n)
            // auto stack = std::stack<char>{};

            // for (auto i = 0U; i < s.size(); ++i) {
            //     const auto c = s[i];

            //     if (stack.empty()) {
            //         stack.push(c);

            //         continue;
            //     }

            //     if ((c == 'B' && stack.top() == 'A') ||
            //         (c == 'D' && stack.top() == 'C')) {
            //         stack.pop();
            //     } else {
            //         stack.push(c);
            //     }
            // }

            // return stack.size();

            // in-place modification
            // O(n)
            // O(1)
            // write ptr
            auto ans = 0U;

            for (auto i = 0U; i < s.size(); ++i) {
                s[ans] = s[i];

                if (ans > 0 && (s[ans - 1] == 'A' || s[ans - 1] == 'C') &&
                    s[ans] == s[ans - 1] + 1) {
                    --ans;
                } else {
                    ++ans;
                }
            }

            return ans;
        }
};
