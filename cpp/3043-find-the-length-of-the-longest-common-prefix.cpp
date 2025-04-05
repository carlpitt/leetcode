#include <memory>
#include <unordered_set>
#include <vector>

using uint = unsigned;

class [[nodiscard]] Solution {
    public:
        [[nodiscard]] constexpr auto longestCommonPrefix(
            const std::vector<int> &arr1,
            const std::vector<int> &arr2
        ) const -> uint {
            // // hash set
            // // O(m * log(M) + n * log(N))
            // // O(m * log(M))
            // auto prefixes = std::unordered_set<int>{};

            // for (auto x : arr1) {
            //     while (!prefixes.contains(x) && x > 0) {
            //         prefixes.insert(x);

            //         x /= 10;
            //     }
            // }

            // auto ans = 0U;

            // for (auto x : arr2) {
            //     while (!prefixes.contains(x) && x > 0) {
            //         x /= 10;
            //     }

            //     if (x > 0) {
            //         ans = std::max(ans, static_cast<uint>(std::log10(x) +
            //         1));
            //     }
            // }

            // return ans;

            // trie
            // O(m * d + n * d) == O(m + n)
            // O(m * d) == O(m)
            class [[nodiscard]] Trie {
                public:
                    constexpr Trie() : root{std::make_unique<TrieNode>()} {}

                    constexpr auto insert(const int num) const -> void {
                        const auto num_str = std::to_string(num);
                        auto node = this->root.get();

                        for (const auto c : num_str) {
                            const auto i = static_cast<uint>(c - '0');
                            auto &child = node->children[i];

                            if (child == nullptr) {
                                child = std::make_unique<TrieNode>();
                            }

                            node = child.get();
                        }
                    }

                    [[nodiscard]] constexpr auto find_longest_prefix(
                        const int num
                    ) const -> uint {
                        const auto num_str = std::to_string(num);
                        const auto *node = this->root.get();
                        auto ans = 0U;

                        for (const auto c : num_str) {
                            const auto i = static_cast<uint>(c - '0');
                            const auto &child = node->children[i];

                            if (child == nullptr) {
                                break;
                            }

                            node = child.get();
                            ++ans;
                        }

                        return ans;
                    }

                private:
                    struct [[nodiscard]] TrieNode {
                            std::array<std::unique_ptr<TrieNode>, 10> children;
                    };

                    std::unique_ptr<TrieNode> root;
            };

            const auto trie = Trie{};

            for (const auto num : arr1) {
                trie.insert(num);
            }

            auto ans = 0U;

            for (const auto num : arr2) {
                const auto len = trie.find_longest_prefix(num);
                ans = std::max(ans, len);
            }

            return ans;
        }
};
