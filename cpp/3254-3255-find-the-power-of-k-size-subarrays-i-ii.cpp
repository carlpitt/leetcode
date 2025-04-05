#include <deque>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto resultsArray(
            const std::vector<int> &nums,
            const uint k
        ) const noexcept -> std::vector<int> {
            // // 1. brute force
            // // O(n * k)
            // // O(n) including output
            // const auto n = nums.size();
            // auto ans = std::vector(n - k + 1, -1);

            // for (auto i = 0; i < n - k + 1; ++i) {
            //     auto consecutive_sorted = true;

            //     for (auto j = i; j < i + k - 1; ++j) {
            //         if (nums[j] + 1 != nums[j + 1]) {
            //             consecutive_sorted = false;

            //             break;
            //         }
            //     }

            //     if (consecutive_sorted) {
            //         ans[i] = nums[i + k - 1];
            //     }
            // }

            // return ans;

            // // 2. sliding window with deque
            // // O(n)
            // // O(k) + O(n) including output
            // const auto n = nums.size();
            // auto ans = std::vector(n - k + 1, -1);
            // auto index_deq = std::deque<uint>{};

            // for (auto i = 0U; i < n; ++i) {
            //     if (!index_deq.empty() && index_deq.front() + k < i + 1) {
            //         index_deq.pop_front();
            //     }

            //     if (!index_deq.empty() && nums[i - 1] + 1 != nums[i]) {
            //         index_deq.clear();
            //     }

            //     index_deq.push_back(i);

            //     if (i >= k - 1 && index_deq.size() == k) {
            //         ans[i - k + 1] = nums[index_deq.back()];
            //     }
            // }

            // return ans;

            // 3. counter
            // O(n)
            // O(n) including output
            if (k == 1) {
                return nums;
            }

            const auto n = nums.size();
            auto ans = std::vector(n - k + 1, -1);
            auto consecutive_count = 1U;

            for (auto i = 0U; i < n - 1; ++i) {
                if (nums[i] + 1 == nums[i + 1]) {
                    ++consecutive_count;
                } else {
                    consecutive_count = 1;
                }

                if (consecutive_count >= k) {
                    ans[i - k + 2] = nums[i + 1];
                }
            }

            return ans;
        }
};
