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
            auto fac = std::vector(n + 1, u64{1});

            for (auto i = 1U; i <= n; ++i) {
                fac[i] = fac[i - 1] * i;
            }

            auto ans = u64{0};
            auto vis = std::unordered_set<std::string>{};
            auto base = static_cast<uint>(std::pow(10, (n - 1) / 2));

            for (auto i = base; i < base * 10; ++i) {
                auto s = std::to_string(i);
                auto rev = s;

                std::ranges::reverse(rev);

                s += rev.substr(n % 2);

                if (std::stoll(s) % k) {
                    continue;
                }

                auto t = s;

                std::ranges::sort(t);

                if (vis.contains(t)) {
                    continue;
                }

                vis.insert(t);

                auto cnt = std::vector(10, 0U);

                for (const auto c : t) {
                    ++cnt[c - '0'];
                }

                auto res = (n - cnt[0]) * fac[n - 1];

                for (const auto x : cnt) {
                    res /= fac[x];
                }

                ans += res;
            }

            return ans;
        }
};
