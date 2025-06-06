#include <array>
#include <string>

using uint = unsigned;

class Solution {
    public:
        static constexpr auto robotWithString =
            [] [[nodiscard]] (const std::string &s) noexcept -> std::string {
            auto count = std::array<uint, 'z' - 'a' + 1>{};

            for (const auto c : s) {
                ++count[static_cast<uint>(c - 'a')];
            }

            auto ans = std::string{};
            auto t = std::string{};
            auto min_c = 'a';

            for (const auto c : s) {
                --count[static_cast<uint>(c - 'a')];

                while (min_c < 'z' && count[static_cast<uint>(min_c - 'a')] == 0
                ) {
                    ++min_c;
                }

                t.push_back(c);

                while (!t.empty() && t.back() <= min_c) {
                    ans.push_back(t.back());
                    t.pop_back();
                }
            }

            return ans;
        };
};
