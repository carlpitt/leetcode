#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto lexicalOrder(const uint n) const noexcept
            -> std::vector<int> {
            // // dfs
            // auto ans = std::vector<int>{};

            // ans.reserve(n);

            // for (auto start = 1U; start <= 9; ++start) {
            //     generate_lexical_nums(ans, start, n);
            // }

            // return ans;

            // iterative
            auto curr = 1U;
            auto ans = std::vector<int>{};

            ans.reserve(n);

            for (auto i = 0U; i < n; ++i) {
                ans.push_back(static_cast<int>(curr));

                if (curr * 10 <= n) {
                    curr *= 10;

                    continue;
                }

                while (curr % 10 == 9 || curr == n) {
                    curr /= 10;
                }

                ++curr;
            }

            return ans;
        }

    private:
        constexpr auto generate_lexical_nums(
            std::vector<int> &ans,
            const uint curr,
            const uint n
        ) const noexcept -> void {
            if (curr > n) {
                return;
            }

            ans.push_back(static_cast<int>(curr));

            for (auto next_digit = 0U; next_digit <= 9; ++next_digit) {
                const auto next_num = 10 * curr + next_digit;

                if (next_num > n) {
                    break;
                }

                generate_lexical_nums(ans, next_num, n);
            }
        }
};
