function heightChecker(heights: readonly number[]): number {
    const freqs: number[] = Array(101).fill(0);
    for (const height of heights) {
        ++freqs[height];
    }

    let curr = 1;
    let ans = 0;

    for (const height of heights) {
        while (freqs[curr] === 0) {
            ++curr;
        }

        if (curr !== height) {
            ++ans;
        }

        --freqs[curr];
    }

    return ans;
}
