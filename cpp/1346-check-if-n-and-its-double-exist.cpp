#include <unordered_map>
#include <unordered_set>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto checkIfExist(
            const std::vector<int> &arr
        ) const noexcept -> bool {
            // // 1. brute force
            // // O(n**2)
            // // O(1)
            // const auto n = arr.size();

            // for (auto i = 0U; i < n; ++i) {
            //     for (auto j = 0U; j < n; ++j) {
            //         if (i != j && arr[i] == 2 * arr[j]) {
            //             return true;
            //         }
            //     }
            // }

            // return false;

            // // 2. set lookup
            // // O(n)
            // // O(n)
            // auto set = std::unordered_set<int>{};

            // for (const auto x : arr) {
            //     if (set.contains(2 * x) || (x % 2 == 0 && set.contains(x /
            //     2))) {
            //         return true;
            //     }

            //     set.insert(x);
            // }

            // return false;

            // // 3. sorting and binary search
            // // O(n * log(n))
            // // O(log(n)) for sort
            // std::ranges::sort(arr);

            // for (auto i = 0U; i < arr.size(); ++i) {
            //     const auto target = 2 * arr[i];
            //     const auto index = [&arr, target]() {
            //         auto left = 0;
            //         auto right = static_cast<int>(arr.size() - 1);

            //         while (left <= right) {
            //             const auto mid = left + (right - left) / 2;

            //             if (arr[mid] == target) {
            //                 return static_cast<int>(mid);
            //             }

            //             if (arr[mid] < target) {
            //                 left = mid + 1;
            //             } else {
            //                 right = mid - 1;
            //             }
            //         }

            //         return -1;
            //     }();

            //     if (index != -1 && index != i) {
            //         return true;
            //     }
            // }

            // return false;

            // 4. frequency hash map
            // O(n)
            // O(n)
            auto map = std::unordered_map<int, uint>{};

            for (const auto x : arr) {
                ++map[x];
            }

            for (const auto x : arr) {
                if ((x == 0 && map[0] > 1) || (x != 0 && map.contains(2 * x))) {
                    return true;
                }
            }

            return false;
        }
};
