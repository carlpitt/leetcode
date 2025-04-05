pub struct Solution;

impl Solution {
    pub fn three_consecutive_odds(arr: &[i32]) -> bool {
        let mut consecutive_odds = 0;

        for num in arr {
            // if num can be < 0
            // consecutive_odds = (num % 2).abs() * (consecutive_odds + 1);
            consecutive_odds = (num % 2) * (consecutive_odds + 1);
            if consecutive_odds == 3 {
                return true;
            }
        }

        false
    }
}
