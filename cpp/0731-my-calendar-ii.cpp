#include <array>
#include <map>
#include <vector>

using uint = unsigned;

class MyCalendarTwo {
    public:
        [[nodiscard]] auto book(const uint start, const uint end) noexcept
            -> bool {
            // overlapped intervals
            // O(n)
            // O(n)
            // todo: translate to std::all_of or std::none_of
            for (const auto booking : this->overlap_bookings) {
                if (does_overlap(booking[0], booking[1], start, end)) {
                    return false;
                }
            }

            for (const auto booking : this->bookings) {
                if (does_overlap(booking[0], booking[1], start, end)) {
                    this->overlap_bookings.push_back(
                        {std::max(booking[0], start), std::min(booking[1], end)}
                    );
                }
            }

            this->bookings.push_back({start, end});

            return true;

            // // line sweep
            // // O(n * log(n))
            // // O(n)
            // ++this->booking_count[start];
            // --this->booking_count[end];
            // auto overlapped_booking = 0;

            // for (const auto [_, count] : this->booking_count) {
            //     overlapped_booking += count;

            //     if (overlapped_booking > this->max_overlapped_booking) {
            //         --this->booking_count[start];
            //         ++this->booking_count[end];

            //         if (this->booking_count[start] == 0) {
            //             this->booking_count.erase(start);
            //         }

            //         if (this->booking_count[end] == 0) {
            //             this->booking_count.erase(end);
            //         }

            //         return false;
            //     }
            // }

            // return true;
        }

    private:
        std::vector<std::array<uint, 2>> bookings;
        std::vector<std::array<uint, 2>> overlap_bookings;

        // std::map<int, int> booking_count;
        // int max_overlapped_booking = 2;

        [[nodiscard]] constexpr auto does_overlap(
            const uint start1,
            const uint end1,
            const uint start2,
            const uint end2
        ) const noexcept -> bool {
            return std::max(start1, start2) < std::min(end1, end2);
        }
};

// Your MyCalendarTwo object will be instantiated and called as such:
// auto obj = MyCalendarTwo{};
// const auto param_1 = obj.book(start, end);
