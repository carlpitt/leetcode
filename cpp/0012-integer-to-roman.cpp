#include <array>
#include <string>
#include <string_view>

using std::literals::operator""sv;

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto intToRoman(uint num) const noexcept
            -> std::string {
            // // 1.
            // // O(1)
            // // O(1)
            // constexpr auto m =
            //     std::array{std::string_view{}, "M"sv, "MM"sv, "MMM"sv};
            // constexpr auto c = std::array{
            //     std::string_view{},
            //     "C"sv,
            //     "CC"sv,
            //     "CCC"sv,
            //     "CD"sv,
            //     "D"sv,
            //     "DC"sv,
            //     "DCC"sv,
            //     "DCCC"sv,
            //     "CM"sv,
            // };
            // constexpr auto x = std::array{
            //     std::string_view{},
            //     "X"sv,
            //     "XX"sv,
            //     "XXX"sv,
            //     "XL"sv,
            //     "L"sv,
            //     "LX"sv,
            //     "LXX"sv,
            //     "LXXX"sv,
            //     "XC"sv,
            // };
            // constexpr auto i = std::array{
            //     std::string_view{},
            //     "I"sv,
            //     "II"sv,
            //     "III"sv,
            //     "IV"sv,
            //     "V"sv,
            //     "VI"sv,
            //     "VII"sv,
            //     "VIII"sv,
            //     "IX"sv,
            // };

            // auto ans = std::string{};

            // ans.reserve(3 + 4 + 4 + 4);

            // ans.append(m[num / 1000]);
            // ans.append(c[(num % 1000) / 100]);
            // ans.append(x[(num % 100) / 10]);
            // ans.append(i[num % 10]);

            // return ans;

            // 2.
            // O(1)
            // O(1)
            auto ans = std::string{};

            ans.reserve(3 + 4 + 4 + 4);

            while (num >= 1000) {
                ans.push_back('M');
                num -= 1000;
            }

            if (num >= 900) {
                ans.append("CM"sv);
                num -= 900;
            }

            if (num >= 500) {
                ans.push_back('D');
                num -= 500;
            }

            if (num >= 400) {
                ans.append("CD"sv);
                num -= 400;
            }

            while (num >= 100) {
                ans.push_back('C');
                num -= 100;
            }

            if (num >= 90) {
                ans.append("XC"sv);
                num -= 90;
            }

            if (num >= 50) {
                ans.push_back('L');
                num -= 50;
            }

            if (num >= 40) {
                ans.append("XL"sv);
                num -= 40;
            }

            while (num >= 10) {
                ans.push_back('X');
                num -= 10;
            }

            if (num >= 9) {
                ans.append("IX"sv);
                num -= 9;
            }

            if (num >= 5) {
                ans.push_back('V');
                num -= 5;
            }

            if (num >= 4) {
                ans.append("IV"sv);
                num -= 4;
            }

            while (num >= 1) {
                ans.push_back('I');
                num -= 1;
            }

            return ans;
        }
};
