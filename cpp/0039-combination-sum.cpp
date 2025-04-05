#include <algorithm>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto combinationSum(
            std::vector<int> &candidates,
            const int target
        ) -> std::vector<std::vector<int>> {
            std::ranges::sort(candidates);

            auto ans = std::vector<std::vector<int>>{};
            auto combo = std::vector<int>{};

            backtrack(ans, combo, candidates, target, 0);

            return ans;
        }

    private:
        constexpr auto backtrack(
            std::vector<std::vector<int>> &ans,
            std::vector<int> &combo,
            const std::vector<int> &candidates,
            const int target,
            const uint start
        ) -> void {
            if (target == 0) {
                ans.push_back(combo);

                return;
            }

            for (auto i = start; i < candidates.size(); ++i) {
                const auto candidate = candidates[i];

                if (target < candidate) {
                    break;
                }

                combo.push_back(candidate);
                backtrack(ans, combo, candidates, target - candidate, i);
                combo.pop_back();
            }
        }
};
