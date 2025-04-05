use std::collections::BTreeMap;

pub struct Solution;

impl Solution {
    pub fn max_profit_assignment(
        difficulty: &[i32],
        profit: &[i32],
        worker: Vec<i32>,
    ) -> i32 {
        let n = difficulty.len();
        let mut ans = 0;

        // let mut jobs = vec![(0, 0); n];

        // for i in 0..n {
        //     jobs[i] = (difficulty[i], profit[i]);
        // }

        // worker.sort_unstable();
        // jobs.sort_unstable();

        // let mut i = 0;
        // let mut best = 0;

        // for ability in worker {
        //     while i < n && ability >= jobs[i].0 {
        //         best = best.max(jobs[i].1);
        //         i += 1;
        //     }

        //     ans += best;
        // }

        let mut jobs = BTreeMap::new();

        for i in 0..n {
            let entry = jobs.entry(difficulty[i]).or_insert(0);
            *entry = (*entry).max(profit[i]);
        }

        let mut max_profit_so_far = 0;

        for profit in jobs.values_mut() {
            max_profit_so_far = max_profit_so_far.max(*profit);
            *profit = max_profit_so_far;
        }

        for ability in worker {
            ans += jobs.range(..=ability).next_back().map_or(0, |(_, &v)| v);
        }

        ans
    }
}
