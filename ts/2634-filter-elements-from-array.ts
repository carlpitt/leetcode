type Fn<T> = (n: T, i: number) => unknown;

function filter<T>(arr: T[], fn: Fn<T>): T[] {
    // // 1.
    // // O(n)
    // // O(n) including output
    // const ans: T[] = [];

    // for (let i = 0; i < arr.length; ++i) {
    //     const x = arr[i];

    //     if (fn(x, i)) {
    //         ans.push(x);
    //     }
    // }

    // return ans;

    // 2.
    // O(n)
    // O(1)
    let j = 0;

    for (let i = 0; i < arr.length; ++i) {
        const x = arr[i];

        if (fn(x, i)) {
            arr[j] = x;
            ++j;
        }
    }

    arr.length = j;

    return arr;
}
