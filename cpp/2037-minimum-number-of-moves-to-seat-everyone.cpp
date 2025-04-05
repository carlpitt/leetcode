#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
    public:
        [[nodiscard]] auto minMovesToSeat(
            std::vector<int> &seats,
            std::vector<int> &students
        ) -> int {
            std::sort(seats.begin(), seats.end());
            std::sort(students.begin(), students.end());

            auto total_moves = 0;
            for (auto i = 0U; i < seats.size(); ++i) {
                total_moves += std::abs(seats[i] - students[i]);
            }

            return total_moves;
        }
};
