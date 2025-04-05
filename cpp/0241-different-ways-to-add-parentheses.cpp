#include <string>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto diffWaysToCompute(const std::string &expr
        ) const -> std::vector<int> {
            // switch (n) {
            // case 0:
            //     return {};
            // case 1:
            //     return {expr[0] - '0'};
            // case 2:
            //     // if (is_digit(expr[0]))
            //     return {10 * (expr[0] - '0') + expr[1] - '0'};
            // }

            // auto ans = std::vector<int>{};

            // for (auto i = 0U; i < n; ++i) {
            //     const auto c = expr[i];

            //     if (is_digit(c)) {
            //         continue;
            //     }

            //     const auto left = diffWaysToCompute(expr.substr(0, i));
            //     const auto right = diffWaysToCompute(expr.substr(i + 1));

            //     for (const auto left_val : left) {
            //         for (const auto right_val : right) {
            //             switch (c) {
            //             case '+':
            //                 ans.push_back(left_val + right_val);

            //                 break;
            //             case '-':
            //                 ans.push_back(left_val - right_val);

            //                 break;
            //             case '*':
            //                 ans.push_back(left_val * right_val);

            //                 break;
            //             }
            //         }
            //     }
            // }

            // return ans;

            const auto n = expr.size();
            auto dp = std::vector(n, std::vector<std::vector<int>>(n));

            // init base cases
            for (auto i = 0U; i < n; ++i) {
                if (!is_digit(expr[i])) {
                    continue;
                }

                const auto dig1 = expr[i] - '0';

                if (i + 1 < n && is_digit(expr[i + 1])) {
                    const auto dig2 = expr[i + 1] - '0';

                    dp[i][i + 1].push_back(10 * dig1 + dig2);
                }

                dp[i][i].push_back(dig1);
            }

            for (auto len = 3U; len <= n; ++len) {
                for (auto start = 0U; start + len - 1 < n; ++start) {
                    const auto end = start + len - 1;

                    process_subexpr(dp, expr, start, end);
                }
            }

            return dp[0][n - 1];
        }

    private:
        [[nodiscard]] constexpr auto is_digit(const char c) const noexcept
            -> bool {
            return c >= '0' && c <= '9';
        }

        constexpr auto process_subexpr(
            std::vector<std::vector<std::vector<int>>> &dp,
            const std::string &expr,
            const uint start,
            const uint end
        ) const -> void {
            for (auto split = start; split <= end; ++split) {
                if (is_digit(expr[split])) {
                    continue;
                }

                const auto &left = dp[start][split - 1];
                const auto &right = dp[split + 1][end];

                compute_results(left, right, expr[split], dp[start][end]);
            }
        }

        constexpr auto compute_results(
            const std::vector<int> &left,
            const std::vector<int> &right,
            const char op,
            std::vector<int> &results
        ) const -> void {
            for (const auto left_val : left) {
                for (const auto right_val : right) {
                    switch (op) {
                        case '+':
                            results.push_back(left_val + right_val);
                            break;
                        case '-':
                            results.push_back(left_val - right_val);
                            break;
                        default:
                            results.push_back(left_val * right_val);
                            break;
                    }
                }
            }
        }
};
