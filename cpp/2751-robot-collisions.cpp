#include <algorithm>
#include <stack>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto survivedRobotsHealths(
            const std::vector<int> &positions,
            std::vector<int> &healths,
            const std::string &directions
        ) -> std::vector<int> {
            const auto n = positions.size();
            auto indices = std::vector<unsigned>(n);

            for (auto i = 0U; i < n; ++i) {
                indices[i] = i;
            }

            std::sort(
                indices.begin(),
                indices.end(),
                [&positions](const unsigned lhs, const unsigned rhs) {
                    return positions[lhs] < positions[rhs];
                }
            );

            auto stack = std::stack<unsigned>{};

            for (const auto curr_index : indices) {
                if (directions[curr_index] == 'R') {
                    stack.push(curr_index);

                    continue;
                }

                while (!stack.empty() && healths[curr_index] > 0) {
                    const auto top_index = stack.top();

                    if (healths[top_index] > healths[curr_index]) {
                        healths[top_index] -= 1;
                        healths[curr_index] = 0;
                    } else if (healths[top_index] < healths[curr_index]) {
                        healths[curr_index] -= 1;
                        healths[top_index] = 0;
                        stack.pop();
                    } else {
                        healths[curr_index] = 0;
                        healths[top_index] = 0;
                        stack.pop();
                    }
                }
            }

            auto ans = std::vector<int>{};

            for (auto i = 0U; i < n; ++i) {
                if (healths[i] > 0) {
                    ans.push_back(healths[i]);
                }
            }

            return ans;
        }
};
