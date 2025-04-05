#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto rotateTheBox(
            const std::vector<std::vector<char>> &box
        ) const noexcept -> std::vector<std::vector<char>> {
            // // 2. row by row (optimized brute force)
            // // O(m * n)
            // // O(m * n) including output
            // const auto m = box.size();
            // const auto n = box[0].size();
            // auto ans = std::vector(n, std::vector(m, '.'));

            // for (auto i = 0U; i < n; ++i) {
            //     for (auto j = 0U; j < m; ++j) {
            //         ans[i][j] = box[m - j - 1][i];
            //     }
            // }

            // for (auto col = 0U; col < m; ++col) {
            //     auto next_obstacle = n;

            //     for (auto i = 0U; i < n; ++i) {
            //         const auto row = n - i - 1;

            //         if (ans[row][col] == '*') {
            //             next_obstacle = row;
            //         } else if (ans[row][col] == '#') {
            //             ans[row][col] = '.';
            //             --next_obstacle;
            //             ans[next_obstacle][col] = '#';
            //         }
            //     }
            // }

            // return ans;

            // 3. combine rotation and gravity operations
            // O(m * n)
            // O(m * n)
            const auto m = box.size();
            const auto n = box[0].size();
            auto ans = std::vector(n, std::vector(m, '.'));

            for (auto i = 0U; i < m; ++i) {
                auto next_obstacle = n;

                for (auto k = 0U; k < n; ++k) {
                    const auto j = n - k - 1;

                    if (box[i][j] == '*') {
                        next_obstacle = j;
                        ans[next_obstacle][m - i - 1] = '*';
                    } else if (box[i][j] == '#') {
                        --next_obstacle;
                        ans[next_obstacle][m - i - 1] = '#';
                    }
                }
            }

            return ans;
        }
};
