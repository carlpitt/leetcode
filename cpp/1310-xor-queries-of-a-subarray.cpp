#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto xorQueries(
            std::vector<int> &arr,
            const std::vector<std::vector<int>> &queries
        ) const -> std::vector<int> {
            for (auto i = 1U; i < arr.size(); ++i) {
                arr[i] ^= arr[i - 1];
            }

            auto ans = std::vector<int>{};

            for (const auto &q : queries) {
                const auto start = static_cast<uint>(q[0]);
                const auto end = static_cast<uint>(q[1]);

                if (start > 0) {
                    ans.push_back(arr[start - 1] ^ arr[end]);
                } else {
                    ans.push_back(arr[end]);
                }
            }

            return ans;
        }
};
