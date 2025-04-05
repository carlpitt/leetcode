pub struct Solution;

impl Solution {
    pub fn sort_array(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();

        // shellsort
        let mut gap = n / 2;

        while gap > 0 {
            for i in gap..n {
                let temp = nums[i];
                let mut j = i;

                while j >= gap && nums[j - gap] > temp {
                    nums[j] = nums[j - gap];
                    j -= gap;
                }

                nums[j] = temp;
            }

            gap /= 2;
        }

        nums
    }
}
