#include <algorithm>
#include <cstdint>

using uint = unsigned;
using u64 = std::uint64_t;

class [[nodiscard]] Solution {
    public:
        [[nodiscard]] constexpr auto
        findKthNumber(const uint n, uint k) const noexcept -> uint {
            auto ans = 1U;
            --k;

            while (k > 0) {
                const auto step = count_steps(n, ans, ans + 1);

                if (step <= k) {
                    ++ans;
                    k -= step;
                } else {
                    ans *= 10;
                    --k;
                }
            }

            return ans;
        }

    private:
        [[nodiscard]] constexpr auto
        count_steps(const uint n, u64 prefix1, u64 prefix2) const noexcept
            -> uint {
            auto ans = 0U;

            while (prefix1 <= n) {
                ans += std::min(u64{n + 1}, prefix2) - prefix1;
                prefix1 *= 10;
                prefix2 *= 10;
            }

            return ans;
        }
};
