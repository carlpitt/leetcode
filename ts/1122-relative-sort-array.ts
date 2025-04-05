function relativeSortArray(arr1: number[], arr2: readonly number[]): number[] {
    // const counts: { [key: number]: number } = {};
    const counts: number[] = Array(1001).fill(0);
    for (const n of arr1) {
        ++counts[n];
    }

    let i = 0;

    for (const n of arr2) {
        while (counts[n] > 0) {
            arr1[i] = n;
            --counts[n];
            ++i;
        }
    }

    for (let n = 0; n < counts.length; ++n) {
        while (counts[n] > 0) {
            arr1[i] = n;
            --counts[n];
            ++i;
        }
    }

    return arr1;
}
