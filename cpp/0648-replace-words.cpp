#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
    public:
        std::array<TrieNode *, 26> children{};
        bool is_end{false};
};

class Solution {
    public:
        [[nodiscard]] auto replaceWords(
            const std::vector<std::string> &dictionary,
            const std::string &sentence
        ) -> std::string {
            auto root = TrieNode{};
            for (const auto &word : dictionary) {
                auto node = &root;
                for (const auto c : word) {
                    const auto i = static_cast<unsigned>(c - 'a');
                    if (node->children[i] == nullptr) {
                        node->children[i] = new TrieNode{};
                    }
                    node = node->children[i];
                }
                node->is_end = true;
            }

            auto ss = std::istringstream{sentence};
            auto word = std::string{};
            word.reserve(1000);
            auto prefix = std::string{};
            prefix.reserve(100);
            auto ans = std::string{};
            ans.reserve(sentence.size() + 1);
            while (ss >> word) {
                const auto *node = &root;
                for (const auto c : word) {
                    const auto i = static_cast<unsigned>(c - 'a');
                    const auto *const child = node->children[i];
                    if (child == nullptr) {
                        break;
                    }
                    prefix += c;
                    node = child;
                    if (node->is_end) {
                        break;
                    }
                }
                ans += node->is_end ? prefix : word;
                ans += ' ';
                prefix.clear();
            }

            // remove last space
            ans.pop_back();

            return ans;
        }
};
