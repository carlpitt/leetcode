#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto findAllRecipes(
            const std::vector<std::string> &recipes,
            const std::vector<std::vector<std::string>> &ingredients,
            const std::vector<std::string> &supplies
        ) -> std::vector<std::string> {
            const auto n = recipes.size();
            auto s = std::unordered_set<std::string>{};

            for (const auto &x : supplies) {
                s.insert(x);
            }

            auto graph =
                std::unordered_map<std::string, std::vector<std::string>>{};
            auto in_degree = std::unordered_map<std::string, int>{};

            for (const auto &x : recipes) {
                in_degree[x] = 0;
            }

            for (auto i = 0U; i < n; ++i) {
                const auto &ingredient_list = ingredients[i];

                for (auto j = 0U; j < ingredient_list.size(); ++j) {
                    const auto &ingredient = ingredient_list[j];

                    if (!s.contains(ingredient)) {
                        const auto &recipe = recipes[i];

                        graph[ingredient].push_back(recipe);

                        ++in_degree[recipe];
                    }
                }
            }

            auto q = std::queue<std::string>{};

            for (const auto &x : in_degree) {
                if (x.second == 0) {
                    q.push(x.first);
                }
            }

            auto ans = std::vector<std::string>{};

            ans.reserve(n);

            while (!q.empty()) {
                const auto &t = q.front();

                for (const auto &x : graph[t]) {
                    auto &d = in_degree[x];
                    --d;

                    if (d == 0) {
                        q.push(x);
                    }
                }

                ans.push_back(t);
                q.pop();
            }

            return ans;
        }
};
