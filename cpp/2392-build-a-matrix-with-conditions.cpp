#include <queue>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto buildMatrix(
            const unsigned k,
            const std::vector<std::vector<int>> &row_conditions,
            const std::vector<std::vector<int>> &col_conditions
        ) -> std::vector<std::vector<int>> {
            const auto order_rows = topo_sort(row_conditions, k);
            const auto order_columns = topo_sort(col_conditions, k);

            if (order_rows.empty() || order_columns.empty()) {
                return std::vector<std::vector<int>>{};
            }

            auto ans = std::vector<std::vector<int>>(k, std::vector<int>(k));

            for (auto i = 0U; i < k; ++i) {
                for (auto j = 0U; j < k; ++j) {
                    if (order_rows[i] == order_columns[j]) {
                        ans[i][j] = order_rows[i];
                    }
                }
            }

            return ans;
        }

    private:
        [[nodiscard]] constexpr auto topo_sort(
            const std::vector<std::vector<int>> &edges,
            unsigned n
        ) -> std::vector<int> {
            auto adj = std::vector<std::vector<int>>(n + 1);
            auto deg = std::vector<int>(n + 1);
            for (const auto &x : edges) {
                adj[x[0]].push_back(x[1]);

                ++deg[x[1]];
            }

            auto q = std::queue<unsigned>{};

            for (auto i = 1U; i <= n; ++i) {
                if (deg[i] == 0) {
                    q.push(i);
                }
            }

            auto ans = std::vector<int>{};

            while (!q.empty()) {
                const auto f = q.front();
                q.pop();
                ans.push_back(f);
                for (const auto &v : adj[f]) {
                    --deg[v];
                    if (deg[v] == 0) {
                        q.push(v);
                    }
                }
                --n;
            }

            if (n > 0) {
                return std::vector<int>{};
            }

            return ans;
        }
};
