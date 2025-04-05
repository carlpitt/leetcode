pub struct Solution;

impl Solution {
    #[allow(clippy::cast_sign_loss)]
    pub fn frequency_sort(mut nums: Vec<i32>) -> Vec<i32> {
        let mut freq = [0; 201];

        for n in &nums {
            freq[(n + 100) as usize] += 1;
        }

        nums.sort_unstable_by(|a, b| {
            let a_u = (a + 100) as usize;
            let b_u = (b + 100) as usize;

            freq[a_u].cmp(&freq[b_u]).then_with(|| b.cmp(a))
        });

        nums
    }
}
