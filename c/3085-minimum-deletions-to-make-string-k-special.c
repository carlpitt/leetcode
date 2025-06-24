typedef unsigned uint;

static uint minimumDeletions(const char *const word, const uint k) {
    uint freq[26] = {0};
    uint i = 0;

    while (word[i] != '\0') {
        ++freq[word[i] - 'a'];
        ++i;
    }

    uint ans = i;

    for (i = 0; i < 26; ++i) {
        const uint a = freq[i];
        uint curr = 0;

        for (uint j = 0; j < 26; ++j) {
            const uint b = freq[j];

            if (a > b) {
                curr += b;
            } else if (b > a + k) {
                curr += b - (a + k);
            }
        }

        if (curr < ans) {
            ans = curr;
        }
    }

    return ans;
}
