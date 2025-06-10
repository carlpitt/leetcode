class Solution {
    public:
        [[nodiscard]] constexpr auto
        differenceOfSums(const int n, const int m) const noexcept -> int {
            // // 1.
            // // O(n)
            // // O(1)
            // auto ans = 0;

            // for (auto i = 1U; i <= n; ++i) {
            //     if (i % m == 0) {
            //         ans -= i;
            //     } else {
            //         ans += i;
            //     }
            // }

            // return ans;

            // 2.
            // O(1)
            // O(1)
            // constexpr auto sum_to = [](const uint x) { return x * (x + 1) /
            // 2; }; const auto total_sum = sum_to(n); const auto num2 = m *
            // sum_to(n / m); const auto num1 = total_sum - num2;

            // return num1 - num2;

            return n * (n + 1) / 2 - m * (n / m) * (n / m + 1);
        }
};
