#include <array>
#include <cstdint>
#include <unordered_map>
#include <vector>

using i64 = std::int64_t;

class Solution {
    public:
        [[nodiscard]] constexpr auto dividePlayers(const std::vector<int> &skill
        ) const noexcept -> i64 {
            // // sorting
            // // O(n * log(n))
            // // O(log(n)) for sorting
            // std::ranges::sort(skill);

            // const auto n = skill.size();
            // const auto team_skill = skill[0] + skill[n - 1];
            // auto ans = i64{skill[0] * skill[n - 1]};

            // for (auto i = 1U; i < n / 2; ++i) {
            //     if (skill[i] + skill[n - i - 1] != team_skill) {
            //         return -1;
            //     }

            //     ans += skill[i] * skill[n - i - 1];
            // }

            // return ans;

            // frequency table
            // O(n)
            // O(1)
            const auto n = skill.size();
            auto total_skill = 0;
            auto skill_freqs = std::array<int, 1001>{};

            for (const auto s : skill) {
                total_skill += s;
                ++skill_freqs[s];
            }

            if (total_skill % (n / 2) != 0) {
                return -1;
            }

            const auto team_skill = total_skill / (n / 2);
            auto ans = i64{0};

            for (const auto s : skill) {
                const auto partner_skill = team_skill - s;

                if (skill_freqs[partner_skill] == 0) {
                    return -1;
                }

                ans += s * partner_skill;
                --skill_freqs[partner_skill];
            }

            return ans / 2;

            // // hash map
            // // O(n)
            // // O(n)
            // const auto n = skill.size();
            // auto total_skill = 0;
            // auto skill_freqs = std::unordered_map<int, int>{};

            // for (const auto s : skill) {
            //     total_skill += s;
            //     ++skill_freqs[s];
            // }

            // if (total_skill % (n / 2) != 0) {
            //     return -1;
            // }

            // const auto team_skill = total_skill / (n / 2);
            // auto ans = i64{0};

            // for (const auto [s, freq] : skill_freqs) {
            //     const auto partner_skill = team_skill - s;

            //     if (!skill_freqs.contains(partner_skill) ||
            //         freq != skill_freqs[partner_skill]) {
            //         return -1;
            //     }

            //     ans += s * partner_skill * freq;
            // }

            // return ans / 2;
        }
};
