#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumTime(
            const std::vector<std::vector<int>> &grid
        ) const noexcept -> int {
            // modified dijkstra's algo
            // O(m * n * log(m * n))
            // O(m * n)
            if (grid[0][1] > 1 && grid[1][0] > 1) {
                return -1;
            }

            constexpr auto directions = std::array<std::array<int, 2>, 4>{
                {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}
            };
            const auto rows = grid.size();
            const auto cols = grid[0].size();
            auto visited = std::vector(rows, std::vector(cols, false));
            auto pq = std::priority_queue<
                std::array<uint, 3>,
                std::vector<std::array<uint, 3>>,
                std::greater<>>{};

            pq.push({static_cast<uint>(grid[0][0]), 0U, 0U});

            while (!pq.empty()) {
                const auto [time, row, col] = pq.top();

                pq.pop();

                if (row == rows - 1 && col == cols - 1) {
                    return time;
                }

                if (visited[row][col]) {
                    continue;
                }

                visited[row][col] = true;

                for (const auto d : directions) {
                    if ((row == 0 && d[0] == -1) || (col == 0 && d[1] == -1)) {
                        continue;
                    }

                    const auto next_row = row + d[0];
                    const auto next_col = col + d[1];

                    if (next_row >= visited.size() ||
                        next_col >= visited[0].size() ||
                        visited[next_row][next_col]) {
                        continue;
                    }

                    const auto wait_time = static_cast<uint>(
                        (grid[next_row][next_col] - time) % 2 == 0
                    );
                    const auto next_time = std::max(
                        static_cast<uint>(grid[next_row][next_col]) + wait_time,
                        time + 1
                    );

                    pq.push({next_time, next_row, next_col});
                }
            }

            // unreachable : can only fail at beginning
            return -1;
        }
};
