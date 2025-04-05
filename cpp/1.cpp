// https://leetcode.com/problems/two-sum

#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>

template<typename M, typename K>
bool contains(const M &m, const K &k) {
    return m.find(k) != m.end();
}

class Solution {
    public:
        std::vector<int> two_sum(const std::vector<int> &nums, const int target)
            const noexcept {
            auto map = std::unordered_map<int, int>{};
            for (auto i = 0ULL, n = nums.size(); i < n; ++i) {
                // TODO
                auto complement = target - nums[i];
                //  map.find(complement) != map.end()
                if (map.contains(complement)) {
                    return {map[complement], static_cast<int>(i)};
                }
                map[nums[i]] = i;
            }
            return nums;
        }
};

int main() {
    auto sol = Solution{};
    for (auto i : sol.two_sum({3, 3}, 6))
        std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}
