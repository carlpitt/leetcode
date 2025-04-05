#include <string>
#include <unordered_set>

class Solution {
    public:
        [[nodiscard]] auto longestPalindrome(const std::string &s) -> int {
            auto non_paired_letters = std::unordered_set<char>{};
            for (const auto c : s) {
                if (non_paired_letters.contains(c)) {
                    non_paired_letters.erase(c);
                } else {
                    non_paired_letters.insert(c);
                }
            }
            return static_cast<int>(
                s.size() - non_paired_letters.size() +
                !non_paired_letters.empty()
            );
        }
};
