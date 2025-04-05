#include <algorithm>
#include <cmath>
#include <string>

using std::literals::operator""s;

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto convertDateToBinary(const std::string &date
        ) const noexcept -> std::string {
            // date == "1900-01-01"s => "11101101100-1-1"s;
            // date == "2100-12-31"s => "100000110100-1100-11111"s;
            auto year = 0U;
            auto month = 0U;
            auto day = 0U;

            std::from_chars(&date[0], &date[4], year);
            std::from_chars(&date[5], &date[7], month);
            std::from_chars(&date[8], &date[10], day);

            auto ans = std::string{};

            ans.reserve(12 + 4 + 5 + 2);

            ans += bin(year);
            ans += '-';
            ans += bin(month);
            ans += '-';
            ans += bin(day);

            return ans;
        }

    private:
        [[nodiscard]] constexpr auto bin(uint x) const noexcept -> std::string {
            if (x == 0) {
                return "0"s;
            }

            auto ans = std::string{};

            // ans.reserve(static_cast<uint>(std::log2(x)) + 1);
            // ans.reserve(static_cast<uint>(std::ceil(std::log2(x + 1))));

            while (x > 0) {
                ans += (x & 1) + '0';
                x >>= 1;
            }

            std::ranges::reverse(ans);

            return ans;
        }
};
