type F = (...args: unknown[]) => void;

function debounce(fn: F, t: number): F {
    let timer: ReturnType<typeof setTimeout>;

    return (...args: unknown[]) => {
        clearTimeout(timer);

        // timer = setTimeout(fn, t, ...args);
        timer = setTimeout(() => fn(...args), t);
    };
}

const log = debounce(console.log, 100);

log("Hello"); // cancelled
log("Hello"); // cancelled
log("Hello"); // Logged at t=100ms
