#include <stack>
#include <string>
#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] auto parseBoolExpr(
            const std::string &expression
        ) const noexcept -> bool {
            // // 1. string manipulation
            // // O(n^2)
            // // O(n)
            // while (expression.size() > 1) {
            //     const auto start = expression.find_last_of("!&|");
            //     const auto end = expression.find(')', start);
            //     const auto sub_expr = expression.substr(start, end - start +
            //     1); const auto result = evaluate_sub_expr(sub_expr);

            //     expression.replace(start, end - start + 1, 1, result);
            // }

            // return expression[0] == 't';

            // // 2. recursive
            // // O(n)
            // // O(n)
            // auto i = 0U;

            // return evaluate(expression, i);

            // // 3. stack
            // // O(n)
            // // O(n)
            // auto st = std::stack<char>{};

            // for (const auto c : expression) {
            //     if (c == ')') {
            //         auto values = std::vector<char>{};

            //         while (st.top() != '(') {
            //             values.push_back(st.top());
            //             st.pop();
            //         }

            //         st.pop();

            //         const auto op = st.top();

            //         st.pop();

            //         const auto ans = evaluate_sub_expr(op, values);

            //         st.push(ans);
            //     } else if (c != ',') {
            //         st.push(c);
            //     }
            // }

            // return st.top() == 't';

            // 4. optimized stack
            // O(n)
            // O(n)
            auto st = std::stack<char>{};

            for (const auto c : expression) {
                if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                    st.push(c);

                    continue;
                }

                if (c != ')') {
                    // c in ",("
                    continue;
                }

                auto has_true = false;
                auto has_false = false;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    const auto top = st.top();

                    st.pop();

                    if (top == 't') {
                        has_true = true;
                    }

                    if (top == 'f') {
                        has_false = true;
                    }
                }

                const auto op = st.top();

                st.pop();

                if (op == '!') {
                    if (has_true) {
                        st.push('f');
                    } else {
                        st.push('t');
                    }
                } else if (op == '&') {
                    if (has_false) {
                        st.push('f');
                    } else {
                        st.push('t');
                    }
                } else if (has_true) {
                    st.push('t');
                } else {
                    st.push('f');
                }
            }

            return st.top() == 't';
        }

    private:
        [[nodiscard]] constexpr auto evaluate_sub_expr(
            const std::string &sub_expr
        ) const noexcept -> char {
            const auto op = sub_expr[0];
            const auto values = sub_expr.substr(2, sub_expr.size() - 3);

            if (op == '!') {
                return values[0] == 't' ? 'f' : 't';
            }

            if (op == '&') {
                return values.find('f') != std::string::npos ? 'f' : 't';
            }

            if (op == '|') {
                return values.find('t') != std::string::npos ? 't' : 'f';
            }

            // unreachable
            return 'f';
        }

        [[nodiscard]] constexpr auto
        evaluate(const std::string &expr, uint &i) const noexcept -> bool {
            const auto c = expr[i];
            ++i;

            if (c == 't') {
                return true;
            }

            if (c == 'f') {
                return false;
            }

            if (c == '!') {
                ++i;
                const auto ans = !evaluate(expr, i);
                ++i;

                return ans;
            }

            auto values = std::vector<bool>{};
            ++i;

            while (expr[i] != ')') {
                if (expr[i] == ',') {
                    ++i;
                } else {
                    values.push_back(evaluate(expr, i));
                }
            }

            ++i;

            if (c == '&') {
                for (const auto v : values) {
                    if (!v) {
                        return false;
                    }
                }

                return true;
            }

            if (c == '|') {
                for (const auto v : values) {
                    if (v) {
                        return true;
                    }
                }

                return false;
            }

            // unreachable
            return false;
        }

        [[nodiscard]] constexpr auto evaluate_sub_expr(
            const char op,
            const std::vector<char> &values
        ) const noexcept -> char {
            if (op == '!') {
                return values[0] == 't' ? 'f' : 't';
            }

            if (op == '&') {
                for (const auto v : values) {
                    if (v == 'f') {
                        return 'f';
                    }
                }

                return 't';
            }

            if (op == '|') {
                for (const auto v : values) {
                    if (v == 't') {
                        return 't';
                    }
                }

                return 'f';
            }

            // unreachable
            return 'f';
        }
};
