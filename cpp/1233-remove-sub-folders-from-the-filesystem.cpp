#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto removeSubfolders(
            const std::vector<std::string> &folder
        ) const noexcept -> std::vector<std::string> {
            // // 1. set
            // // O(n * len^2)
            // // O(n * len)
            // auto folder_set =
            //     std::unordered_set<std::string>{folder.begin(),
            //     folder.end()};
            // auto ans = std::vector<std::string>{};

            // for (const auto& f : folder) {
            //     auto is_sub_folder = false;
            //     auto prefix = f;

            //     while (!prefix.empty()) {
            //         auto pos = prefix.find_last_of('/');

            //         if (pos == std::string::npos) {
            //             break;
            //         }

            //         // prefix = prefix.substr(0, pos);
            //         prefix.erase(pos);

            //         if (folder_set.contains(prefix)) {
            //             is_sub_folder = true;

            //             break;
            //         }
            //     }

            //     if (!is_sub_folder) {
            //         ans.push_back(f);
            //     }
            // }

            // return ans;

            // // 2. sorting
            // // O(n * len * log(n))
            // // O(n * len)
            // std::ranges::sort(folder);

            // const auto n = folder.size();
            // auto ans = std::vector<std::string>{};

            // ans.reserve(n);
            // ans.push_back(folder[0]);

            // for (auto i = 1U; i < n; ++i) {
            //     const auto& f = folder[i];
            //     auto last_folder = ans.back() + '/';

            //     if (f.compare(0, last_folder.size(), last_folder) != 0) {
            //         ans.push_back(f);
            //     }
            // }

            // return ans;

            // 3. trie
            // O(n * len)
            // O(n * len)
            struct TrieNode {
                    bool leaf = false;
                    std::unordered_map<std::string, TrieNode> children;
            };

            auto root = TrieNode{};

            for (const auto &path : folder) {
                auto curr = &root;
                auto iss = std::istringstream{path};
                auto folder_name = std::string{};

                while (std::getline(iss, folder_name, '/')) {
                    if (folder_name.empty()) {
                        continue;
                    }

                    curr = &curr->children[folder_name];

                    if (curr->leaf) {
                        break;
                    }
                }

                curr->leaf = true;
            }

            auto ans = std::vector<std::string>{};

            for (const auto &path : folder) {
                auto curr = &root;
                auto iss = std::istringstream{path};
                auto folder_name = std::string{};
                auto is_sub_folder = false;

                while (std::getline(iss, folder_name, '/')) {
                    if (folder_name.empty()) {
                        continue;
                    }

                    const auto next = &curr->children[folder_name];

                    if (next->leaf && iss.rdbuf()->in_avail() != 0) {
                        is_sub_folder = true;
                    }

                    curr = next;
                }

                if (!is_sub_folder) {
                    ans.push_back(path);
                }
            }

            return ans;

            // // mine
            // // O(n * len * log(n))
            // // O(n * len)
            // std::ranges::sort(folder);

            // const auto* prefix = &folder[0];
            // const auto n = folder.size();
            // auto ans = std::vector<std::string>{};

            // ans.reserve(n);

            // for (const auto& f : folder) {
            //     if (!f.starts_with(*prefix) || f[prefix->size()] != '/') {
            //         ans.push_back(f);

            //         prefix = &f;
            //     }
            // }

            // return ans;
        }
};
