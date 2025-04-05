#include <algorithm>
#include <string>

class Solution {
    public:
        [[nodiscard]] auto addBinary(const std::string &a, const std::string &b)
            -> std::string {
            auto ans = std::string{};
            auto i = a.size();
            auto j = b.size();
            auto carry = 0;

            while (i > 0 || j > 0 || carry > 0) {
                if (i > 0) {
                    carry += a[i - 1] - '0';
                    --i;
                }
                if (j > 0) {
                    carry += b[j - 1] - '0';
                    --j;
                }

                ans.push_back(static_cast<char>(carry % 2 + '0'));
                carry /= 2;
            }

            std::reverse(ans.begin(), ans.end());

            return ans;
        }
};
