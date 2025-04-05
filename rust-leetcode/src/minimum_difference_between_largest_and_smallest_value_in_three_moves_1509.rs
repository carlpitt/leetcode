pub struct Solution;

impl Solution {
    pub fn min_difference(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n < 5 {
            return 0;
        }

        // selection algorithm
        let mut min_nums = [i32::MAX; 4];
        let mut max_nums = [i32::MIN; 4];

        for num in nums {
            for i in 0..4 {
                if num < min_nums[i] {
                    for j in (i + 1..4).rev() {
                        min_nums[j] = min_nums[j - 1];
                    }

                    min_nums[i] = num;

                    break;
                }
            }
            for i in 0..4 {
                if num > max_nums[i] {
                    for j in (i + 1..4).rev() {
                        max_nums[j] = max_nums[j - 1];
                    }

                    max_nums[i] = num;

                    break;
                }
            }
        }

        let mut ans = i32::MAX;

        for i in 0..4 {
            ans = ans.min(max_nums[i] - min_nums[3 - i]);
        }

        ans
    }
}
