#include <array>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto groupAnagrams(const std::vector<std::string> &strs)
            -> std::vector<std::vector<std::string>> {
            auto map =
                std::unordered_map<std::string, std::vector<std::string>>{};
            auto key = std::string{};

            key.reserve((1 + 3) * 26);

            for (const auto &s : strs) {
                auto counts = std::array<int, 26>{};

                for (const auto c : s) {
                    ++counts[static_cast<std::size_t>(c - 'a')];
                }

                for (auto i = std::size_t{0}; i < 26; ++i) {
                    key.push_back('#');
                    key.append(std::to_string(counts[i]));
                }

                map[key].push_back(s);
                key.clear();
            }

            auto ans = std::vector<std::vector<std::string>>{};

            ans.reserve(map.size());

            // TODO: convert to std::transform
            for (const auto &pair : map) {
                ans.push_back(pair.second);
            }

            return ans;
        }
};
