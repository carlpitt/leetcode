pub struct Solution;

impl Solution {
    #[allow(clippy::cast_possible_wrap)]
    #[allow(clippy::cast_sign_loss)]
    pub fn maximum_importance(n: i32, roads: Vec<Vec<i32>>) -> i64 {
        let mut counts = vec![0; n as usize];

        for r in roads {
            counts[r[0] as usize] += 1;
            counts[r[1] as usize] += 1;
        }

        counts.sort_unstable();

        let mut ans = 0;

        for (i, count) in counts.into_iter().enumerate() {
            ans += (i + 1) * count;
        }

        ans as i64
    }
}
