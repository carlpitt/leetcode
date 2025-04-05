#include <numeric>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto finalValueAfterOperations(
            const std::vector<std::string> &operations
        ) const noexcept -> int {
            return std::accumulate(
                operations.begin(),
                operations.end(),
                0,
                [](const int init, const std::string &op) {
                    // // 1.
                    // if (op[1] == '+') {
                    //     return init + 1;
                    // }

                    // return init - 1;

                    // 2.
                    return init + 2 * static_cast<int>(op[1] == '+') - 1;

                    // // these last 2 assume that '+' is 2 chars before '-' in
                    // // the char encoding
                    // // 3.
                    // return init + '+' + 1 - op[1];
                    // // 4.
                    // return init + '-' - 1 - op[1];
                }
            );
        }
};
