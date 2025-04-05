type JsonValue =
    | null
    | boolean
    | number
    | string
    | JsonValue[]
    | { [key: string]: JsonValue };
type Fn = (...args: JsonValue[]) => void;

function cancellable(fn: Fn, args: JsonValue[], t: number): () => void {
    // // 1.
    // // O(1)
    // // O(1)
    // let cancelled = false;

    // setTimeout(() => {
    //     if (!cancelled) {
    //         fn(...args);
    //     }
    // }, t);

    // return () => {
    //     cancelled = true;
    // };

    // 2.
    // O(1)
    // O(1)
    // const timer = setTimeout(() => {
    //     // fn.apply(null, args);
    //     fn(...args);
    // }, t);
    const timer = setTimeout(fn, t, ...args);

    return () => {
        clearTimeout(timer);
    };
}

// const result = [];
// const fn = (x) => x * 5;
// const args = [2];
// const t = 20;
// const cancelTimeMs = 50;

// const start = performance.now();

// const log = (...argsArr) => {
//     const diff = Math.floor(performance.now() - start);

//     result.push({ time: diff, returned: fn(...argsArr) });
// };
// const cancel = cancellable(log, args, t);
// const maxT = Math.max(t, cancelTimeMs);

// setTimeout(cancel, cancelTimeMs);
// setTimeout(() => {
//     console.log(result); // [{"time": 20, "returned": 10}]
// }, maxT + 15);
