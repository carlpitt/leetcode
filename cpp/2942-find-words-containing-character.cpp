#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto findWordsContaining(
            const std::vector<std::string> &words,
            const char x
        ) const noexcept -> std::vector<int> {
            auto ans = std::vector<int>{};

            for (auto i = 0U; i < words.size(); ++i) {
                if (words[i].contains(x)) {
                    ans.push_back(static_cast<int>(i));
                }
            }

            return ans;
        }
};
