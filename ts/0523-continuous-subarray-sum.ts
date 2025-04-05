function checkSubarraySum(nums: readonly number[], k: number): boolean {
    const totals: Map<number, number> = new Map([[0, -1]]);
    let total = 0;

    for (let i = 0; i < nums.length; ++i) {
        // k != 0 check not needed
        total = (total + nums[i]) % k;
        if (totals.has(total)) {
            if (i - totals.get(total) > 1) {
                return true;
            }
        } else {
            totals.set(total, i);
        }
    }
    return false;
}
