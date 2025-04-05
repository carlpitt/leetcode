pub struct Solution;

impl Solution {
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let mut ans = 0;

        for log in logs {
            let log = log.as_bytes();

            if log[1] == b'.' {
                ans = (ans - 1).max(0);
            } else if log[0] != b'.' {
                ans += 1;
            }
        }

        ans
    }
}
