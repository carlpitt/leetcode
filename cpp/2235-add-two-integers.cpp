class Solution {
    public:
        static constexpr auto sum =
            [] [[nodiscard]] (const int num1, const int num2) noexcept -> int {
            return num1 + num2;
        };
};
