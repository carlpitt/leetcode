class Solution {
    public:
        static constexpr auto isPalindrome =
            [] [[nodiscard]] (int x) noexcept -> bool {
            if (x < 0 || (x > 0 && x % 10 == 0)) {
                return false;
            }

            auto r = 0;

            while (x > r) {
                r = 10 * r + x % 10;
                x /= 10;
            }

            return x == r / 10 || x == r;
        };
};
