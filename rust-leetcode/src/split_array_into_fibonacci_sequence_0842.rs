pub struct Solution;

impl Solution {
    pub fn split_into_fibonacci(num: &str) -> Vec<i32> {
        let mut nums = Vec::new();
        Self::find_fibonacci_sequence(&mut nums, num, 0, 0, 0);

        nums
    }

    #[allow(clippy::cast_possible_truncation)]
    fn find_fibonacci_sequence(
        nums: &mut Vec<i32>,
        num: &str,
        index: usize,
        sum: u64,
        prev: u64,
    ) -> bool {
        if index == num.len() {
            return nums.len() >= 3;
        }

        let mut curr = 0;

        for i in index..num.len() {
            if i > index && num.chars().nth(index).unwrap() == '0' {
                break;
            }

            curr = 10 * curr
                + u64::from(num.chars().nth(i).unwrap().to_digit(10).unwrap());
            if curr > i32::MAX as u64 {
                break;
            }

            if nums.len() >= 2 {
                if curr < sum {
                    continue;
                }
                if curr > sum {
                    break;
                }
            }

            // nums.push(curr.try_into().unwrap());
            nums.push(curr as i32);

            if Self::find_fibonacci_sequence(
                nums,
                num,
                i + 1,
                prev + curr,
                curr,
            ) {
                return true;
            }

            nums.pop();
        }

        false
    }
}
