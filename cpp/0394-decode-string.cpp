#include <stack>
#include <string>

class Solution {
    public:
        [[nodiscard]] auto decodeString(const std::string &s) -> std::string {
            auto curr_s = std::string{};
            curr_s.reserve(s.size());
            auto curr_n = 0U;
            auto s_stack = std::stack<std::string>{};
            auto n_stack = std::stack<unsigned>{};
            for (const auto c : s) {
                if ('a' <= c && c <= 'z') {
                    curr_s += c;
                } else if ('0' <= c && c <= '9') {
                    curr_n = 10 * curr_n + static_cast<unsigned>(c) - '0';
                } else if (c == '[') {
                    s_stack.push(curr_s);
                    n_stack.push(curr_n);
                    curr_s.clear();
                    curr_n = 0;
                } else {
                    // c is "]"
                    const auto n = n_stack.top();
                    n_stack.pop();
                    auto &prev_s = s_stack.top();
                    prev_s.reserve(prev_s.size() + n * curr_s.size());
                    for (auto i = 0U; i < n; ++i) {
                        prev_s.append(curr_s);
                    }
                    curr_s = prev_s;
                    s_stack.pop();
                }
            }

            return curr_s;
        }
};
