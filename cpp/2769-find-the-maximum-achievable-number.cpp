using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto theMaximumAchievableX(
            const uint num,
            const uint t
        ) const noexcept -> uint {
            return num + 2 * t;
        }
};
