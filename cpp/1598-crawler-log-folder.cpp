#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto minOperations(const std::vector<std::string> &logs)
            -> int {
            auto ans = 0;

            for (const auto &log : logs) {
                if (log[1] == '.') {
                    ans = std::max(ans - 1, 0);
                } else if (log[0] != '.') {
                    ++ans;
                }
            }

            return ans;
        }
};
