class Solution:
    def min_moves_to_seat(self, seats: list[int], students: list[int]) -> int:
        seats.sort()
        students.sort()

        return sum(abs(seat - student) for seat, student in zip(seats, students))
