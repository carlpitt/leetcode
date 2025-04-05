#include <deque>
#include <sstream>
#include <string>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto areSentencesSimilar(
            const std::string &sentence1,
            const std::string &sentence2
        ) const noexcept -> bool {
            // // deque
            // // O(m + n)
            // // O(m + n)
            // auto iss1 = std::istringstream{sentence1};
            // auto vec1 =
            //     std::deque<std::string>{std::istream_iterator<std::string>{iss1},
            //                             std::istream_iterator<std::string>{}};
            // auto iss2 = std::istringstream{sentence2};
            // auto vec2 =
            //     std::deque<std::string>{std::istream_iterator<std::string>{iss2},
            //                             std::istream_iterator<std::string>{}};

            // while (!vec1.empty() && !vec2.empty() && vec1[0] == vec2[0]) {
            //     vec1.pop_front();
            //     vec2.pop_front();
            // }

            // while (!vec1.empty() && !vec2.empty() && vec1.back() ==
            // vec2.back())
            // {
            //     vec1.pop_back();
            //     vec2.pop_back();
            // }

            // return vec1.empty() || vec2.empty();

            // 2 pointers
            // TODO: iterate over the sentences rather than using iss
            // O(m + n)
            // O(m + n)
            auto iss1 = std::istringstream{sentence1};
            auto word = std::string{};
            auto s1words = std::vector<std::string>{};

            while (iss1 >> word) {
                s1words.push_back(word);
            }

            auto iss2 = std::istringstream{sentence2};
            auto s2words = std::vector<std::string>{};

            while (iss2 >> word) {
                s2words.push_back(word);
            }

            if (s1words.size() > s2words.size()) {
                return areSentencesSimilar(sentence2, sentence1);
            }

            auto start = 0U;

            while (start < s1words.size() && s1words[start] == s2words[start]) {
                ++start;
            }

            auto end1 = s1words.size() - 1;
            auto end2 = s2words.size() - 1;

            while (end1 > 0 && s1words[end1] == s2words[end2]) {
                --end1;
                --end2;
            }

            return (end1 == 0 && s1words[0] == s2words[end2]) || end1 < start;
        }
};
