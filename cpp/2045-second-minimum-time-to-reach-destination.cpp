#include <array>
#include <queue>

class Solution {
    public:
        [[nodiscard]] auto secondMinimum(
            const unsigned n,
            const std::vector<std::vector<int>> &edges,
            const int time,
            const int change
        ) -> int {
            auto q = std::queue<std::array<unsigned, 2>>{{{1, 1}}};
            auto dist1 = std::vector<int>(n + 1, -1);
            auto dist2 = std::vector<int>(n + 1, -1);
            dist1[1] = 0;
            auto adj = std::vector<std::vector<unsigned>>(n + 1);

            for (const auto &edge : edges) {
                const auto start = static_cast<unsigned>(edge[0]);
                const auto end = static_cast<unsigned>(edge[1]);

                adj[start].push_back(end);
                adj[end].push_back(start);
            }

            while (!q.empty()) {
                const auto [node, freq] = q.front();

                q.pop();

                auto time_taken = dist1[node];

                if (freq == 2) {
                    time_taken = dist2[node];
                }

                if (time_taken / change % 2) {
                    time_taken = change * (time_taken / change + 1) + time;
                } else {
                    time_taken += time;
                }

                for (const auto &neighbor : adj[node]) {
                    if (dist1[neighbor] == -1) {
                        dist1[neighbor] = time_taken;

                        q.push({neighbor, 1});
                    } else if (dist2[neighbor] == -1 &&
                               dist1[neighbor] != time_taken) {
                        if (neighbor == n) {
                            return time_taken;
                        }

                        dist2[neighbor] = time_taken;

                        q.push({neighbor, 2});
                    }
                }
            }

            return 0;
        }
};
