#include <algorithm>
#include <string>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto longestCommonPrefix(
            const std::vector<std::string> &strs
        ) const noexcept -> std::string {
            // // 1. horizontal scanning
            // // O(s) where s is sum of all chars in all strings
            // // O(1)
            // auto prefix = strs[0];

            // for (auto i = 1U; i < strs.size(); ++i) {
            //     while (strs[i].find(prefix) != 0) {
            //         prefix.pop_back();

            //         if (prefix.empty()) {
            //             return std::string{};
            //         }
            //     }
            // }

            // return prefix;

            // // 2. vertical scanning
            // // O(s) where s is sum of all chars in all strings
            // // O(1)
            // for (auto i = 0U; i < strs[0].size(); ++i) {
            //     for (auto j = 1U; j < strs.size(); ++j) {
            //         if (i == strs[j].size() || strs[j][i] != strs[0][i]) {
            //             return strs[0].substr(0, i);
            //         }
            //     }
            // }

            // return strs[0];

            // // 3. divide and conquer
            // // O(s) where s is sum of all chars in all strings
            // // O(m * log(n)) where we have n equal strings with len m at
            // worst case return longest_common_prefix(strs, 0, strs.size() -
            // 1);

            // // 4. binary search
            // // O(s * log(m))
            // // O(1)
            // // s == sum of all chars in all strings
            // // m : n equal strings with len m at worst case
            // auto low = 1U;
            // auto high = strs[0].size();

            // for (const auto& s : strs) {
            //     high = std::min(high, s.size());
            // }

            // while (low <= high) {
            //     const auto mid = low + (high - low) / 2;

            //     if (is_common_prefix(strs, mid)) {
            //         low = mid + 1;
            //     } else {
            //         high = mid - 1;
            //     }
            // }

            // return strs[0].substr(0, high + (low - high) / 2);

            // // 5. trie
            // // O(s)
            // // O(s)
            // // s == sum of all chars in all strings
            // class [[nodiscard]] TrieNode {
            // public:
            //     std::array<TrieNode*, 26> children{};
            //     bool is_end = false;
            //     uint link_count = 0U;

            //     [[nodiscard]] constexpr auto contains(const char c) const
            //     noexcept
            //         -> bool {
            //         return this->children[c - 'a'] != nullptr;
            //     }
            // };

            // struct [[nodiscard]] Trie {
            //     TrieNode* root = new TrieNode{};
            // };

            // const auto n = strs.size();

            // if (n == 1) {
            //     return strs[0];
            // }

            // auto trie = Trie{};

            // for (auto i = 1U; i < n; ++i) {
            //     // insert
            //     const auto& word = strs[i];
            //     auto node = trie.root;

            //     for (const auto c : word) {
            //         // put
            //         if (!node->contains(c)) {
            //             if (node->children[c - 'a'] == nullptr) {
            //                 node->children[c - 'a'] = new TrieNode{};
            //                 ++node->link_count;
            //             }
            //         }

            //         node = node->children[c - 'a'];
            //     }

            //     node->is_end = true;
            // }

            // // search longest prefix
            // auto node = trie.root;
            // auto ans = std::string{};

            // for (const auto c : strs[0]) {
            //     if (!node->contains(c) || node->link_count != 1 ||
            //     node->is_end)
            //     {
            //         break;
            //     }

            //     ans.push_back(c);
            //     node = node->children[c - 'a'];
            // }

            // return ans;

            // mine
            // O(s)
            // O(1)
            const auto *min_s = &strs[0];
            const auto *max_s = &strs[0];

            for (auto i = 1U; i < strs.size(); ++i) {
                const auto &curr = strs[i];

                if (*min_s > curr) {
                    min_s = &curr;
                } else if (*max_s < curr) {
                    max_s = &curr;
                }
            }

            const auto len = std::min(min_s->size(), max_s->size());
            auto i = 0U;

            while (i < len && (*min_s)[i] == (*max_s)[i]) {
                ++i;
            }

            return min_s->substr(0, i);
        }

    private:
        [[nodiscard]] constexpr auto longest_common_prefix(
            const std::vector<std::string> &strs,
            const uint low,
            const uint high
        ) const noexcept -> std::string {
            if (low == high) {
                return strs[low];
            }

            const auto mid = low + (high - low) / 2;
            // lcp
            const auto left = longest_common_prefix(strs, low, mid);
            const auto right = longest_common_prefix(strs, mid + 1, high);
            // common prefix
            const auto min = std::min(left.size(), right.size());

            for (auto i = 0U; i < std::min(left.size(), right.size()); ++i) {
                if (left[i] != right[i]) {
                    return left.substr(0, i);
                }
            }

            return left.substr(0, min);
        }

        [[nodiscard]] constexpr auto is_common_prefix(
            const std::vector<std::string> &strs,
            const uint len
        ) const noexcept -> bool {
            const auto prefix = strs[0].substr(0, len);

            for (auto i = 1U; i < strs.size(); ++i) {
                if (strs[i].find(prefix) != 0) {
                    return false;
                }
            }

            return true;
        }
};
