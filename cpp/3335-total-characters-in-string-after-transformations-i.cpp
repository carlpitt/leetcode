#include <array>
#include <string>

using uint = unsigned;

class Solution {
    public:
        static constexpr auto lengthAfterTransformations =
            [] [[nodiscard]] (const std::string &s, const uint t) noexcept
            -> uint {
            constexpr auto mod = 1'000'000'007;
            auto a = std::array<uint, 26>{};

            for (const auto c : s) {
                ++a[static_cast<uint>(c - 'a')];
            }

            for (auto round = 0U; round < t; ++round) {
                auto b = std::array<uint, 26>{};
                b['a' - 'a'] = a['z' - 'a'];
                b['b' - 'a'] = a['z' - 'a'] + a['a' - 'a'];
                b['b' - 'a'] %= mod;

                for (auto i = 2U; i < 26; ++i) {
                    b[i] = a[i - 1];
                }

                a = b;
            }

            auto ans = 0U;

            for (auto f : a) {
                ans += f;
                ans %= mod;
            }

            return ans;
        };
};
