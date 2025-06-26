#include <string.h>

typedef unsigned uint;

static uint longestSubsequence(const char *const s, const uint k) {
    const size_t len = strlen(s);
    uint ans = 0;
    uint sum = 0;
    uint t = k;
    uint bits = 0;

    while (t > 0) {
        ++bits;
        t >>= 1;
    }

    for (size_t i = 0; i < len; ++i) {
        const char c = s[len - 1 - i];

        if (c == '0') {
            ++ans;

            continue;
        }

        if (i < bits && sum + (1U << i) <= k) {
            sum += 1U << i;
            ++ans;
        }
    }

    return ans;
}
