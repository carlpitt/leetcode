#include <unordered_map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto intersect(
            const std::vector<int> &nums1,
            const std::vector<int> &nums2
        ) const -> std::vector<int> {
            auto counts = std::unordered_map<int, int>{};

            for (const auto n : nums1) {
                ++counts[n];
            }

            auto ans = std::vector<int>{};

            for (const auto n : nums2) {
                auto &count = counts[n];

                if (count > 0) {
                    ans.push_back(n);

                    --count;
                }
            }

            return ans;

            // std::sort(nums1.begin(), nums1.end());
            // std::sort(nums2.begin(), nums2.end());

            // auto ans = std::vector<int>{};
            // auto i = std::size_t{0};
            // auto j = std::size_t{0};

            // while (i < nums1.size() && j < nums2.size()) {
            //     if (nums1[i] < nums2[j]) {
            //         ++i;
            //     } else if (nums1[i] > nums2[j]) {
            //         ++j;
            //     } else {
            //         ans.push_back(nums1[i]);

            //         ++i;
            //         ++j;
            //     }
            // }

            // return ans;
        }
};
