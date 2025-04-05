#include <array>
#include <set>
#include <vector>

using uint = unsigned;

class [[nodiscard]] MyCalendar {
    public:
        [[nodiscard]] auto book(const uint start, const uint end) -> bool {
            // // brute force
            // // O(n^2)
            // // O(n)
            // for (const auto [s, e] : this->m_v) {
            //     if (start < e && s < end) {
            //         return false;
            //     }
            // }

            // this->m_v.push_back({start, end});

            // return true;

            // sorted list (ordered set) and binary search
            // O(n * log(n))
            // O(n)
            const auto event = std::array{start, end};
            const auto next_event = this->m_set.lower_bound(event);

            if ((next_event != this->m_set.end() && (*next_event)[0] < end) ||
                (next_event != this->m_set.begin() &&
                 (*std::prev(next_event))[1] > start)) {
                return false;
            }

            this->m_set.insert(event);

            return true;
        }

    private:
        // std::vector<std::array<uint, 2>> m_v;
        std::set<std::array<uint, 2>> m_set;
};

// // your MyCalendar object will be instantiated and called as such:
// auto obj = MyCalendar{};
// const auto param_1 = obj.book(start, end);
