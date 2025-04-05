function isNStraightHand(hand: readonly number[], groupSize: number): boolean {
    const counts: number[] = [];

    for (const card of hand) {
        counts[card] = (counts[card] ?? 0) + 1;
    }

    for (const startS in counts) {
        const start = Number(startS);
        const startFreq = counts[start];
        if (startFreq > 0) {
            for (let i = start; i < start + groupSize; ++i) {
                if (counts[i] === undefined || counts[i] < startFreq) {
                    return false;
                }
                counts[i] -= startFreq;
            }
        }
    }

    return true;
}
