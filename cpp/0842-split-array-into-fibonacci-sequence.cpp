#include <cstdint>
#include <limits>
#include <string>
#include <vector>

using u32 = std::uint32_t;
using u64 = std::uint64_t;

class Solution {
    public:
        [[nodiscard]] auto splitIntoFibonacci(const std::string &num)
            -> std::vector<int> {
            auto nums = std::vector<int>{};

            this->find_fibonacci_sequence(nums, num, 0, 0, 0);

            return nums;
        }

    private:
        // backtrack
        auto find_fibonacci_sequence(
            std::vector<int> &nums,
            const std::string &num,
            const u32 index,
            const u64 sum,
            const u64 prev
        ) -> bool {
            if (index == num.size()) {
                return nums.size() >= 3;
            }

            auto curr = u64{0};

            for (auto i = index; i < num.size(); ++i) {
                if (i > index && num[index] == '0') {
                    break;
                }

                curr *= 10;
                curr += static_cast<u64>(num[i]) - '0';

                if (curr > std::numeric_limits<int>::max()) {
                    break;
                }

                if (nums.size() >= 2) {
                    if (curr < sum) {
                        continue;
                    }

                    if (curr > sum) {
                        break;
                    }
                }

                nums.push_back(static_cast<int>(curr));

                if (find_fibonacci_sequence(
                        nums,
                        num,
                        i + 1,
                        prev + curr,
                        curr
                    )) {
                    return true;
                }

                nums.pop_back();
            }

            return false;
        }
};
