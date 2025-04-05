#include <sstream>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] constexpr auto isCircularSentence(
            const std::string &sentence
        ) const noexcept -> bool {
            // // 1. split sentence
            // // O(n)
            // // O(n)
            // auto iss = std::istringstream{sentence};
            // auto word = std::string{};
            // auto words = std::vector<std::string>{};

            // while (iss >> word) {
            //     words.push_back(word);
            // }

            // const auto n = words.size();
            // auto last = words[n - 1].back();

            // for (auto i = 0U; i < n; ++i) {
            //     if (words[i].front() != last) {
            //         return false;
            //     }

            //     last = words[i].back();
            // }

            // return true;

            // 2. space-optimized approach
            // O(n)
            // O(1)
            const auto n = sentence.size();

            for (auto i = 1U; i < n - 1; ++i) {
                if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }

            return sentence[0] == sentence[n - 1];
        }
};
