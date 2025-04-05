// https://leetcode.com/problems/top-k-frequent-elements

#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        std::vector<int> top_k_frequent(
            const std::vector<int> &nums,
            const int k
        ) const noexcept {
            auto count = std::unordered_map<int, unsigned>{};
            // freq = [[] for i in range(len(nums) + 1)]
            auto freq = std::vector<std::vector<int>>(nums.size() + 1);
            // freq.resize(nums.size() + 1);
            // for (std::size_t i{0}, n{nums.size() + 1}; i != n; ++i) {
            //   freq.emplace_back();
            // }

            for (auto n : nums) {
                // count[n] = count.get(n, 0) + 1
                ++count[n];
                // count[n] = count[n] + 1;
            }
            for (auto [n, c] : count) {
                freq[c].push_back(n);
            }

            auto result = std::vector<int>{};
            for (auto i = freq.size() - 1; i != 0; --i) {
                for (auto n : freq[i]) {
                    result.push_back(n);
                    if (result.size() == static_cast<std::size_t>(k)) {
                        return result;
                    }
                }
            }
            // Not necessary
            return result;
        }
};

int main() {
    auto sol = Solution{};
    for (auto i :
         sol.top_k_frequent({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2}, 2)) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    auto i = 8;
    std::cout << i << '\n';
}
