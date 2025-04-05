#include <array>
#include <limits>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumSubarrayLength(
            const std::vector<int> &nums,
            const uint k
        ) const noexcept -> int {
            // // 1. binary search
            // // O(n * log(n))
            // // O(1)
            // auto left = 1U;
            // auto right = nums.size();
            // auto ans = -1;

            // while (left <= right) {
            //     const auto mid = left + (right - left) / 2;

            //     if (has_valid_subarray(nums, k, mid)) {
            //         ans = static_cast<int>(mid);
            //         right = mid - 1;
            //     } else {
            //         left = mid + 1;
            //     }
            // }

            // return ans;

            // 2. sliding window
            // O(n)
            // O(1)
            auto ans = std::numeric_limits<uint>::max();
            auto window_start = 0U;
            auto window_end = 0U;
            auto bit_counts = std::array<uint, 32>{};

            while (window_end < nums.size()) {
                update_bit_counts(
                    bit_counts,
                    static_cast<uint>(nums[window_end]),
                    1
                );

                while (window_start <= window_end &&
                       convert_bit_counts_to_number(bit_counts) >= k) {
                    ans = std::min(ans, window_end - window_start + 1);

                    update_bit_counts(
                        bit_counts,
                        static_cast<uint>(nums[window_start]),
                        -1
                    );

                    ++window_start;
                }

                ++window_end;
            }

            if (ans == std::numeric_limits<uint>::max()) {
                return -1;
            }

            return static_cast<int>(ans);
        }

    private:
        [[nodiscard]] constexpr auto has_valid_subarray(
            const std::vector<int> &nums,
            const uint k,
            const uint window_size
        ) const noexcept -> uint {
            const auto n = nums.size();
            auto bit_counts = std::array<uint, 32>{};

            for (auto right = 0U; right < n; ++right) {
                update_bit_counts(
                    bit_counts,
                    static_cast<uint>(nums[right]),
                    1
                );

                if (right >= window_size) {
                    update_bit_counts(
                        bit_counts,
                        static_cast<uint>(nums[right - window_size]),
                        -1
                    );
                }

                if (right >= window_size - 1 &&
                    convert_bit_counts_to_number(bit_counts) >= k) {
                    return true;
                }
            }

            return false;
        }

        constexpr auto update_bit_counts(
            std::array<uint, 32> &bit_counts,
            const uint num,
            const int delta
        ) const noexcept -> void {
            for (auto bit_pos = 0U; bit_pos < 32; ++bit_pos) {
                if (((num >> bit_pos) & 1) != 0) {
                    bit_counts[bit_pos] += static_cast<uint>(delta);
                }
            }
        }

        [[nodiscard]] constexpr auto convert_bit_counts_to_number(
            const std::array<uint, 32> &bit_counts
        ) const noexcept -> uint {
            auto ans = 0U;

            for (auto bit_pos = 0U; bit_pos < 32; ++bit_pos) {
                if (bit_counts[bit_pos] != 0) {
                    ans |= 1 << bit_pos;
                }
            }

            return ans;
        }
};
