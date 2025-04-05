#include <vector>

using uint = unsigned;

class Solution {
    public:
        [[nodiscard]] constexpr auto constructDistancedSequence(const uint n
        ) const noexcept -> std::vector<int> {
            auto ans = std::vector(2 * n - 1, 0);
            auto is_num_used = std::vector(n + 1, false);

            find_lexicographically_largest_sequence(ans, is_num_used, 0, n);

            return ans;
        }

    private:
        // backtrack
        constexpr auto find_lexicographically_largest_sequence(
            std::vector<int> &sequence,
            std::vector<bool> &is_num_used,
            const uint i,
            const uint n
        ) const noexcept -> bool {
            if (i == sequence.size()) {
                return true;
            }

            if (sequence[i] != 0) {
                return find_lexicographically_largest_sequence(
                    sequence,
                    is_num_used,
                    i + 1,
                    n
                );
            }

            for (auto num_to_place = n; num_to_place >= 1; --num_to_place) {
                if (is_num_used[num_to_place]) {
                    continue;
                }

                is_num_used[num_to_place] = true;
                sequence[i] = static_cast<int>(num_to_place);

                if (num_to_place == 1) {
                    if (find_lexicographically_largest_sequence(
                            sequence,
                            is_num_used,
                            i + 1,
                            n
                        )) {
                        return true;
                    }
                } else if (i + num_to_place < sequence.size() &&
                           sequence[i + num_to_place] == 0) {
                    sequence[i + num_to_place] = static_cast<int>(num_to_place);

                    if (find_lexicographically_largest_sequence(
                            sequence,
                            is_num_used,
                            i + 1,
                            n
                        )) {
                        return true;
                    }

                    sequence[i + num_to_place] = 0;
                }

                sequence[i] = 0;
                is_num_used[num_to_place] = false;
            }

            return false;
        }
};
