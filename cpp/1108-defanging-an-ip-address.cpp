#include <string>
#include <string_view>

using std::literals::operator""sv;

class Solution {
    public:
        [[nodiscard]] constexpr auto defangIPaddr(
            const std::string &address
        ) const noexcept -> std::string {
            // O(n)
            // O(n)
            auto ans = std::string{};

            for (const auto c : address) {
                if (c == '.') {
                    ans += "[.]"sv;
                } else {
                    ans += c;
                }
            }

            return ans;
        }
};
