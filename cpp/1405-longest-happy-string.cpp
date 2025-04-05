#include <queue>
#include <string>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto
        longestDiverseString(uint a, uint b, uint c) const noexcept
            -> std::string {
            // // 1. priority queue
            // // O(a + b + c)
            // // O(1)
            // auto pq = std::priority_queue<std::pair<int, char>>{};

            // if (a > 0) {
            //     pq.push({a, 'a'});
            // }

            // if (b > 0) {
            //     pq.push({a, 'b'});
            // }

            // if (c > 0) {
            //     pq.push({a, 'b'});
            // }

            // auto ans = std::string{};

            // while (!pq.empty()) {
            //     const auto n = ans.size();
            //     auto [count, ch] = pq.top();

            //     pq.pop();

            //     if (n >= 2 && ans[n - 2] == ch && ans[n - 1] == ch) {
            //         if (pq.empty()) {
            //             break;
            //         }

            //         auto [temp_count, temp_ch] = pq.top();

            //         pq.pop();

            //         --temp_count;
            //         ans += temp_ch;

            //         if (temp_count > 0) {
            //             pq.push({temp_count, temp_ch});
            //         }
            //     } else {
            //         --count;
            //         ans += ch;
            //     }

            //     if (count > 0) {
            //         pq.push({count, ch});
            //     }
            // }

            // return ans;

            // 2. greedy
            // O(a + b + c)
            // O(1)
            const auto total_iterations = a + b + c;
            auto curra = 0U;
            auto currb = 0U;
            auto currc = 0U;
            auto ans = std::string{};

            for (auto i = 0U; i < total_iterations; ++i) {
                if ((a >= b && a >= c && curra != 2) ||
                    (a > 0 && (currb == 2 || currc == 2))) {
                    ans += 'a';
                    --a;
                    ++curra;
                    currb = 0;
                    currc = 0;
                } else if ((b >= a && b >= c && currb != 2) ||
                           (b > 0 && (currc == 2 || curra == 2))) {
                    ans += 'b';
                    --b;
                    ++currb;
                    curra = 0;
                    currc = 0;
                } else if ((c >= a && c >= b && currc != 2) ||
                           (c > 0 && (curra == 2 || currb == 2))) {
                    ans += 'c';
                    --c;
                    ++currc;
                    curra = 0;
                    currb = 0;
                }
            }

            return ans;

            // // 3. mine
            // // O(a + b + c)
            // // O(1)
            // auto ans = std::string{};

            // while (a > 0 || b > 0 || c > 0) {
            //     auto ch = ' ';

            //     if (a >= b && a >= c) {
            //         ch = 'a';
            //     } else if (b >= a && b >= c) {
            //         ch = 'b';
            //     } else {
            //         ch = 'c';
            //     }

            //     const auto n = ans.size();

            //     if (n < 2 || ans[n - 2] != ch || ans[n - 1] != ch) {
            //         ans += ch;

            //         switch (ch) {
            //         case 'a':
            //             --a;
            //             break;
            //         case 'b':
            //             --b;
            //             break;
            //         case 'c':
            //             --c;
            //             break;
            //         }
            //     } else if (ch == 'a') {
            //         if (b == 0 && c == 0) {
            //             break;
            //         }

            //         if (b > c) {
            //             ans += 'b';
            //             --b;
            //         } else {
            //             ans += 'c';
            //             --c;
            //         }
            //     } else if (ch == 'b') {
            //         if (a == 0 && c == 0) {
            //             break;
            //         }

            //         if (a > c) {
            //             ans += 'a';
            //             --a;
            //         } else {
            //             ans += 'c';
            //             --c;
            //         }
            //     } else {
            //         if (a == 0 && b == 0) {
            //             break;
            //         }

            //         if (a > b) {
            //             ans += 'a';
            //             --a;
            //         } else {
            //             ans += 'b';
            //             --b;
            //         }
            //     }
            // }

            // return ans;
        }
};
