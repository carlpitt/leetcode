#include <array>
#include <set>
#include <unordered_set>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto robotSim(
            const std::vector<int> &commands,
            const std::vector<std::vector<int>> &obstacles
        ) const noexcept -> int {
            // auto obstacle_set = std::set<std::array<int, 2>>{};
            auto obstacle_set = std::unordered_set<int>{};

            for (const auto &obstacle : obstacles) {
                obstacle_set.insert(hash_coords(obstacle[0], obstacle[1]));
            }

            // north, east, south, west
            constexpr auto dirs = std::array<std::array<int, 2>, 4>{
                {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
            };
            auto dir_i = 0U;
            auto x = 0;
            auto y = 0;
            auto ans = 0;

            for (const auto command : commands) {
                if (command == -1) {
                    dir_i = (dir_i + 1) % 4;

                    continue;
                }

                if (command == -2) {
                    dir_i = (dir_i + 3) % 4;

                    continue;
                }

                // move forward
                const auto dir = dirs[dir_i];

                for (auto i = 0; i < command; ++i) {
                    const auto next_x = x + dir[0];
                    const auto next_y = y + dir[1];

                    if (obstacle_set.contains(hash_coords(next_x, next_y))) {
                        break;
                    }

                    x = next_x;
                    y = next_y;
                }

                ans = std::max(ans, x * x + y * y);
            }

            return ans;
        }

    private:
        // slightly > 2 * max coord value
        static constexpr auto HASH_MULTIPLIER = 60'013;

        [[nodiscard]] constexpr auto
        hash_coords(const int x, const int y) const noexcept -> int {
            return x + HASH_MULTIPLIER * y;
        }
};
