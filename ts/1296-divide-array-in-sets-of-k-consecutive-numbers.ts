function isPossibleDivide(nums: readonly number[], k: number): boolean {
    const counts: number[] = [];

    for (const card of nums) {
        counts[card] = (counts[card] ?? 0) + 1;
    }

    for (const startS in counts) {
        const start = Number(startS);
        const startFreq = counts[start];
        if (startFreq > 0) {
            for (let i = start; i < start + k; ++i) {
                if (counts[i] === undefined || counts[i] < startFreq) {
                    return false;
                }
                counts[i] -= startFreq;
            }
        }
    }

    return true;
}
