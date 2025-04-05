#include <cmath>
#include <map>
#include <optional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto countOfAtoms(const std::string &formula)
            -> std::string {
            const auto n = formula.size();
            auto curr_num = std::optional<unsigned>{};
            auto running_mul = 1U;
            auto stack = std::stack<unsigned>{{1}};
            auto muls = std::vector<unsigned long>(n);

            for (auto i = n - 1; i > 0; --i) {
                const auto c = formula[i];

                if (std::isdigit(c)) {
                    if (curr_num.has_value()) {
                        if (*curr_num == 0) {
                            curr_num = static_cast<unsigned>(c - '0') * 10;
                        } else {
                            *curr_num +=
                                static_cast<unsigned>(c - '0') *
                                static_cast<unsigned>(std::pow(
                                    10,
                                    static_cast<unsigned>(std::log10(*curr_num)
                                    ) + 1
                                ));
                        }
                    } else {
                        curr_num = static_cast<unsigned>(c - '0');
                    }
                } else if (std::isalpha(c)) {
                    curr_num = {};
                } else if (c == ')') {
                    auto curr_multiplier = 1U;

                    if (curr_num.has_value()) {
                        curr_multiplier = *curr_num;
                    }

                    running_mul *= curr_multiplier;

                    stack.push(curr_multiplier);
                    curr_num = {};
                } else if (c == '(') {
                    running_mul /= stack.top();

                    stack.pop();
                    curr_num = {};
                }

                muls[i] = running_mul;
            }

            if (formula[0] == '(') {
                running_mul /= stack.top();

                stack.pop();
            }

            muls[0] = running_mul;

            auto i = 0U;
            auto map = std::unordered_map<std::string, unsigned long>{};

            while (i < n) {
                if (!std::isupper(formula[i])) {
                    ++i;

                    continue;
                }

                auto atom = std::string{formula[i]};
                ++i;

                while (i < n && std::islower(formula[i])) {
                    atom.push_back(formula[i]);
                    ++i;
                }

                auto count = std::string{};

                while (i < n && std::isdigit(formula[i])) {
                    count.push_back(formula[i]);
                    ++i;
                }

                if (count.empty()) {
                    map[atom] += muls[i - 1];
                } else {
                    map[atom] += std::stoul(count) * muls[i - 1];
                }
            }

            auto ans = std::string{};
            auto sorted_map =
                std::map<std::string, unsigned long>{map.begin(), map.end()};

            for (const auto &[atom, count] : sorted_map) {
                ans.append(atom);

                if (count > 1) {
                    ans.append(std::to_string(count));
                }
            }

            return ans;
        }
};
