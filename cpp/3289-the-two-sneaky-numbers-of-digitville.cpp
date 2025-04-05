#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto getSneakyNumbers(const std::vector<int> &nums
        ) const noexcept -> std::vector<int> {
            // // 1. sort
            // // O(n * log(n))
            // // O(std::ranges::sort(nums)) ?
            // std::ranges::sort(nums);

            // auto ans = std::vector{-1, -1};

            // for (auto i = 1U; i < nums.size(); ++i) {
            //     if (vc[i - 1] == vc[i]) {
            //         ans.push_back(vc[i]);
            //     }
            // }

            // return ans;

            // // 2. set
            // // O(n)
            // // O(n)
            // auto ans = std::vector{-1, -1};
            // auto freqs = std::vector(nums.size() - 2, 0U);

            // for (const auto num : nums) {
            //     if (freqs[num] == 1) {
            //         if (ans[0] == -1) {
            //             ans[0] = num;
            //         } else {
            //             ans[1] = num;

            //             return ans;
            //         }
            //     } else {
            //         ++freqs[num];
            //     }
            // }

            // return ans;

            // 3. math
            // O(n)
            // O(1)
            auto sum = 0;
            auto sq = 0;

            for (const auto num : nums) {
                sum += num;
                sq += num * num;
            }

            const auto n = static_cast<int>(nums.size() - 2);
            const auto sumTot = (n - 1) * n / 2;
            const auto sqTot = (n - 1) * n * (2 * n - 1) / 6;
            const auto aPb = sum - sumTot;
            const auto asqPbsq = sq - sqTot;
            const auto aMb =
                static_cast<int>(std::sqrt(2 * asqPbsq - aPb * aPb));

            return std::vector{(aPb + aMb) / 2, (aPb - aMb) / 2};
        }
};
