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

    // traverse number pairs
    for (uint i = 0; i < nums_size; ++i) {
        for (uint j = 0; j < nums_size; ++j) {
            if (nums[j] == key && i <= k + j && j <= k + i) {
                ans[count] = i;
                ++count;

                break;
            }
        }
    }

    *return_size = count;

    return ans;
}
