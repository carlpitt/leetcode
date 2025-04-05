class Solution:
    def relativeSortArray(self, arr1: list[int], arr2: list[int]) -> list[int]:
        # counts = Counter(arr1)
        counts = 1001 * [0]
        for n in arr1:
            counts[n] += 1

        i = 0

        for n in arr2:
            while counts[n] > 0:
                arr1[i] = n
                counts[n] -= 1
                i += 1

        for n in range(1001):
            while counts[n] > 0:
                arr1[i] = n
                counts[n] -= 1
                i += 1

        return arr1
