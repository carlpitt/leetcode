#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto convertTemperature(const double celsius
        ) const noexcept -> std::vector<double> {
            const auto kelvin = celsius + 273.15;
            const auto fahrenheit = 1.8 * celsius + 32;

            return std::vector{kelvin, fahrenheit};
        }
};
