type P = Promise<number>;

async function addTwoPromises(promise1: P, promise2: P): P {
    // return promise1.then((x) => promise2.then((y) => x + y));

    // return (await promise1) + (await promise2);

    // return Promise.all([promise1, promise2]).then(([x, y]) => x + y);

    const [x, y] = await Promise.all([promise1, promise2]);

    return x + y;
}

// addTwoPromises(Promise.resolve(2), Promise.resolve(2)).then(console.log);
// -> 4
