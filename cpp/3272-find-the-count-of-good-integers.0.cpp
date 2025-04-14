#include <algorithm>
#include <cmath>
#include <cstdint>
#include <string>
#include <unordered_set>
#include <vector>

using uint = unsigned;
using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto
        countGoodIntegers(const uint n, const uint k) const noexcept -> u64 {
            const auto base = static_cast<uint>(std::pow(10, (n - 1) / 2));
            const auto skip = n % 2;
            auto dict = std::unordered_set<std::string>{};

            for (auto i = base; i < 10 * base; ++i) {
                auto s = std::to_string(i);
                s += std::string{s.rbegin() + skip, s.rend()};
                const auto palindromic_int = static_cast<u64>(std::stoll(s));

                if (palindromic_int % k == 0) {
                    std::ranges::sort(s);
                    dict.emplace(s);
                }
            }

            auto factorial = std::vector(n + 1, u64{1});
            auto ans = u64{0};

            for (auto i = 1U; i <= n; ++i) {
                factorial[i] = factorial[i - 1] * i;
            }

            for (const auto &s : dict) {
                auto cnt = std::vector(10, 0U);

                for (const auto c : s) {
                    ++cnt[c - '0'];
                }

                auto tot = (n - cnt[0]) * factorial[n - 1];

                for (const auto x : cnt) {
                    tot /= factorial[x];
                }

                ans += tot;
            }

            return ans;
        }
};
