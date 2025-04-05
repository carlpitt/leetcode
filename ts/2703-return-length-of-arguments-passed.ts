type JsonValue =
    | null
    | boolean
    | number
    | string
    | JsonValue[]
    // | { readonly [key: string]: JsonValue };
    | { [key: string]: JsonValue };

// function argumentsLength(...args: readonly unknown[]): number {
function argumentsLength(...args: readonly JsonValue[]): number {
    return args.length;
}

// argumentsLength(1, 2, 3); // 3
