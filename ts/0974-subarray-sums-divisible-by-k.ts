function subarraysDivByK(nums: readonly number[], k: number): number {
    let prefixSum = 0;
    // const freqs: { [key: number]: number } = { 0: 1 };
    const freqs: number[] = Array(k).fill(0);
    freqs[0] = 1;
    let ans = 0;
    for (const n of nums) {
        prefixSum = (((prefixSum + n) % k) + k) % k;
        // if (freqs[prefixSum] === undefined) {
        //     freqs[prefixSum] = 1;
        // } else {
        //     ans += freqs[prefixSum];
        //     ++freqs[prefixSum];
        // }
        ans += freqs[prefixSum];
        ++freqs[prefixSum];
    }

    return ans;
}
