#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto sortArray(std::vector<int> &nums)
            -> std::vector<int> & {
            const auto n = nums.size();

            // shellsort
            for (auto gap = n / 2; gap > 0; gap /= 2) {
                for (auto i = gap; i < n; ++i) {
                    const auto temp = nums[i];
                    auto j = i;

                    while (j >= gap && nums[j - gap] > temp) {
                        nums[j] = nums[j - gap];
                        j -= gap;
                    }

                    nums[j] = temp;
                }
            }

            return nums;
        }
};
