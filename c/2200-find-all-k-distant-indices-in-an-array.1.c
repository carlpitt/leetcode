#include <stdlib.h>

typedef unsigned uint;

// note: the returned array must be malloced, assume caller calls free()
static uint *findKDistantIndices(
    const uint *const nums,
    const uint nums_size,
    const uint key,
    const uint k,
    uint *const return_size
) {
    uint *const ans = (uint *)malloc(nums_size * sizeof(uint));
    uint count = 0;
    // unjudged min index
    uint right = 0;

    for (uint i = 0; i < nums_size; ++i) {
        if (nums[i] == key) {
            const uint left = ((right + k > i) ? right + k : i) - k;
            right = (i + k + 1 > nums_size) ? nums_size : i + k + 1;

            for (uint j = left; j < right; ++j) {
                ans[count] = j;
                ++count;
            }
        }
    }

    *return_size = count;

    return ans;
}
