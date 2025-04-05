#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using uint = unsigned;

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto minimumPushes(const std::string &word)
            -> uint {
            // auto freqs = std::vector<uint>{};
            // freqs.resize(26);

            // for (const auto c : word) {
            //     ++freqs[static_cast<uint>(c - 'a')];
            // }

            // std::sort(freqs.rbegin(), freqs.rend());

            // auto ans = 0U;

            // for (auto i = 0U; i < 26; ++i) {
            //     const auto freq = freqs[i];

            //     if (freq == 0) {
            //         break;
            //     }

            //     ans += (i / 8 + 1) * freq;
            // }

            // return ans;

            auto freqs = std::vector<uint>{};
            freqs.resize(26);

            for (const auto c : word) {
                ++freqs[static_cast<uint>(c - 'a')];
            }

            auto pq = std::priority_queue<uint>{freqs.begin(), freqs.end()};
            auto ans = 0U;
            auto i = 0U;

            while (!pq.empty()) {
                ans += (i / 8 + 1) * pq.top();
                pq.pop();
                ++i;
            }

            return ans;
        }
};
