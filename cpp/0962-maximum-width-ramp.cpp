#include <algorithm>
#include <stack>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto maxWidthRamp(
            const std::vector<int> &nums
        ) const noexcept -> int {
            // // brute force (TLEs)
            // // O(n^2)
            // // O(1)
            // const int n = nums.size();
            // auto ans = 0;

            // for (auto i = 0; i < n - 1; ++i) {
            //     for (auto j = n - 1; j > i; --j) {
            //         if (nums[i] <= nums[j]) {
            //             ans = std::max(ans, j - i);

            //             break;
            //         }
            //     }
            // }

            // return ans;

            // // sorting
            // // O(n * log(n))
            // // O(n)
            // const int n = nums.size();
            // auto indices = std::vector<int>(n);

            // for (auto i = 0; i < n; ++i) {
            //     indices[i] = i;
            // }

            // std::ranges::sort(indices, [&nums](const int i, const int j) {
            //     if (nums[i] == nums[j]) {
            //         return i < j;
            //     }

            //     return nums[i] < nums[j];
            // });

            // auto ans = 0;
            // auto min_index = n;

            // for (auto i = 0; i < n; ++i) {
            //     ans = std::max(ans, indices[i] - min_index);
            //     min_index = std::min(min_index, indices[i]);
            // }

            // return ans;

            // // 2 pointers
            // // O(n)
            // // O(n)
            // const int n = nums.size();
            // auto right_max = std::vector<int>(n);
            // right_max[n - 1] = nums[n - 1];

            // for (auto i = n - 2; i >= 0; --i) {
            //     right_max[i] = std::max(right_max[i + 1], nums[i]);
            // }

            // auto left = 0;
            // auto right = 0;
            // auto ans = 0;

            // while (right < n) {
            //     while (left < right && nums[left] > right_max[right]) {
            //         ++left;
            //     }

            //     ans = std::max(ans, right - left);
            //     ++right;
            // }

            // return ans;

            // monotonic stack
            // O(n)
            // O(n)
            const auto n = nums.size();
            auto indices = std::stack<uint>{};

            for (auto i = 0U; i < n; ++i) {
                if (indices.empty() || nums[indices.top()] > nums[i]) {
                    indices.push(i);
                }
            }

            auto ans = 0U;

            for (int i = n - 1; i >= 0; --i) {
                while (!indices.empty() && nums[indices.top()] <= nums[i]) {
                    ans = std::max(ans, i - indices.top());

                    indices.pop();
                }
            }

            return ans;
        }
};
