pub struct Solution;

impl Solution {
    pub fn find_the_winner(n: i32, k: i32) -> i32 {
        let mut ans = 0;

        for i in 2..=n {
            ans = (ans + k) % i;
        }

        ans + 1
    }
}
