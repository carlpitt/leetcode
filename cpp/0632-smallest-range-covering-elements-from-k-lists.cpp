#include <algorithm>
#include <array>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto smallestRange(
            const std::vector<std::vector<int>> &nums
        ) const noexcept -> std::vector<int> {
            // // 1. optimal brute force
            // // O(n * k)
            // // O(k)
            // constexpr auto max = std::numeric_limits<int>::max();
            // const auto k = nums.size();
            // auto indices = std::vector(k, 0);
            // auto ans = std::vector{0, max};

            // while (true) {
            //     auto curr_min = max;
            //     auto curr_max = std::numeric_limits<int>::min();
            //     auto min_list_index = 0;

            //     for (auto i = 0; i < k; ++i) {
            //         const auto curr_element = nums[i][indices[i]];

            //         if (curr_element < curr_min) {
            //             curr_min = curr_element;
            //             min_list_index = i;
            //         }

            //         if (curr_element > curr_max) {
            //             curr_max = curr_element;
            //         }
            //     }

            //     if (curr_max - curr_min < ans[1] - ans[0]) {
            //         ans[0] = curr_min;
            //         ans[1] = curr_max;
            //     }

            //     ++indices[min_list_index];

            //     if (indices[min_list_index] == nums[min_list_index].size()) {
            //         break;
            //     }
            // }

            // return ans;

            // // 2. priority queue / heap
            // // O(n * log(k))
            // // O(k)
            // priority_queue<pair<int, pair<int, int>>,
            //                vector<pair<int, pair<int, int>>>, greater<>>
            //     pq;
            // int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

            // for (int i = 0; i < nums.size(); i++) {
            //     pq.push({nums[i][0], {i, 0}});
            //     maxVal = max(maxVal, nums[i][0]);
            // }

            // while (pq.size() == nums.size()) {
            //     auto [minVal, indices] = pq.top();
            //     pq.pop();
            //     int row = indices.first, col = indices.second;

            //     if (maxVal - minVal < rangeEnd - rangeStart) {
            //         rangeStart = minVal;
            //         rangeEnd = maxVal;
            //     }

            //     if (col + 1 < nums[row].size()) {
            //         int nextVal = nums[row][col + 1];
            //         pq.push({nextVal, {row, col + 1}});
            //         maxVal = max(maxVal, nextVal);
            //     }
            // }

            // return {rangeStart, rangeEnd};

            // 3. 2 pointer
            // O(n * log(n))
            // O(n)
            vector<pair<int, int>> merged;

            for (int i = 0; i < nums.size(); i++) {
                for (int num : nums[i]) {
                    merged.push_back({num, i});
                }
            }

            sort(merged.begin(), merged.end());

            unordered_map<int, int> freq;
            int left = 0, count = 0;
            int rangeStart = 0, rangeEnd = INT_MAX;

            for (int right = 0; right < merged.size(); right++) {
                freq[merged[right].second]++;
                if (freq[merged[right].second] == 1)
                    count++;

                while (count == nums.size()) {
                    int curRange = merged[right].first - merged[left].first;
                    if (curRange < rangeEnd - rangeStart) {
                        rangeStart = merged[left].first;
                        rangeEnd = merged[right].first;
                    }

                    freq[merged[left].second]--;
                    if (freq[merged[left].second] == 0)
                        count--;
                    left++;
                }
            }

            return {rangeStart, rangeEnd};
        }
};
