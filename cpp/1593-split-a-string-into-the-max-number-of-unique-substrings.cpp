#include <string>
#include <unordered_set>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto maxUniqueSplit(const std::string &s) const noexcept
            -> uint {
            // // 1. backtracking
            // // O(n * 2^n)
            // // O(n)
            // auto seen = std::unordered_set<std::string>{};

            // return backtrack(s, 0, seen);

            // 2. backtracking with pruning
            // O(n * 2^n)
            // O(n)
            auto seen = std::unordered_set<std::string>{};
            auto ans = 0U;

            backtrack(s, 0, seen, 0, ans);

            return ans;
        }

    private:
        [[nodiscard]] constexpr auto backtrack(
            const std::string &s,
            const uint start,
            std::unordered_set<std::string> &seen
        ) const noexcept -> uint {
            if (start == s.size()) {
                return 0;
            }

            auto ans = 0U;

            for (auto end = start + 1; end <= s.size(); ++end) {
                const auto substr = s.substr(start, end - start);

                if (!seen.contains(substr)) {
                    seen.insert(substr);

                    ans = std::max(ans, backtrack(s, end, seen) + 1);

                    seen.erase(substr);
                }
            }

            return ans;
        }

        constexpr auto backtrack(
            const std::string &s,
            const uint start,
            std::unordered_set<std::string> &seen,
            const uint count,
            uint &max_count
        ) const noexcept -> void {
            if (count + (s.size() - start) <= max_count) {
                return;
            }

            if (start == s.size()) {
                max_count = std::max(max_count, count);

                return;
            }

            for (auto end = start + 1; end <= s.size(); ++end) {
                const auto substr = s.substr(start, end - start);

                if (!seen.contains(substr)) {
                    seen.insert(substr);

                    backtrack(s, end, seen, count + 1, max_count);

                    seen.erase(substr);
                }
            }
        }
};
