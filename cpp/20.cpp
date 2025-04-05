// https://leetcode.com/problems/valid-parentheses

#include <ios>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
    public:
        bool is_valid(std::string s) {
            auto stack = std::stack<char>{};
            auto map = std::unordered_map<char, char>{
                {'(', ')'},
                {'[', ']'},
                {'{', '}'}
            };

            for (auto c : s) {
                if (c == '(' || c == '[' || c == '{') {
                    stack.push(c);
                } else if (!stack.empty() && c == map[stack.top()]) {
                    stack.pop();
                } else {
                    return false;
                }
            }

            return stack.empty();
        }
};

int main() {
    std::cout << std::boolalpha;

    auto sol = Solution{};
    std::cout << sol.is_valid("()") << '\n';
    std::cout << sol.is_valid("()[]{}") << '\n';
    std::cout << sol.is_valid("(]") << '\n';

    return 0;
}
