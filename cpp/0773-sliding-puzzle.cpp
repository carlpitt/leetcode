#include <array>
#include <queue>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::literals::operator""sv;

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto slidingPuzzle(
            const std::vector<std::vector<int>> &board
        ) const noexcept -> int {
            // // 1. depth-first search (dfs)
            // // O((m * n)! * (m * n)**2)
            // // O((m * n)!)
            // auto start_state = std::string{};
            // auto zero_pos = 0U;

            // for (auto i = 0U; i < 2; ++i) {
            //     for (auto j = 0U; j < 3; ++j) {
            //         if (board[i][j] == 0) {
            //             zero_pos = start_state.size();
            //         }

            //         start_state.push_back(static_cast<char>(board[i][j] +
            //         '0'));
            //     }
            // }

            // auto visited = std::unordered_map<std::string, uint>{};

            // dfs(start_state, visited, zero_pos, 0);

            // if (!visited.contains("123450"s)) {
            //     return -1;
            // }

            // return visited["123450"s];

            // 2. breadth-first search (bfs)
            // O((m * n)! * (m * n))
            // O((m * n)!)
            constexpr auto target = "123450"sv;
            const auto directions = std::array<std::vector<uint>, 6>{
                {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}}
            };
            auto start_state = std::string{};

            for (auto i = 0U; i < board.size(); ++i) {
                for (auto j = 0U; j < board[0].size(); ++j) {
                    start_state.push_back(static_cast<char>(board[i][j] + '0'));
                }
            }

            auto visited = std::unordered_set<std::string>{start_state};
            auto q = std::queue<std::string>{{start_state}};
            auto ans = 0;

            while (!q.empty()) {
                const auto size = q.size();

                for (auto i = 0U; i < size; ++i) {
                    const auto curr_state = q.front();

                    q.pop();

                    if (curr_state == target) {
                        return ans;
                    }

                    const auto zero_pos = curr_state.find('0');

                    for (const auto new_pos : directions[zero_pos]) {
                        auto next_state = curr_state;

                        std::swap(next_state[zero_pos], next_state[new_pos]);

                        if (visited.contains(next_state)) {
                            continue;
                        }

                        visited.insert(next_state);
                        q.push(next_state);
                    }
                }

                ++ans;
            }

            return -1;
        }

    private:
        constexpr auto dfs(
            std::string &state,
            std::unordered_map<std::string, uint> &visited,
            const uint zero_pos,
            const uint moves
        ) const noexcept -> void {
            if (visited.contains(state) && visited[state] <= moves) {
                return;
            }

            const auto directions = std::array<std::vector<uint>, 6>{
                {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 5, 1}, {4, 2}}
            };

            visited[state] = moves;

            for (const auto next_pos : directions[zero_pos]) {
                std::swap(state[zero_pos], state[next_pos]);
                dfs(state, visited, next_pos, moves + 1);
                std::swap(state[zero_pos], state[next_pos]);
            }
        }
};
